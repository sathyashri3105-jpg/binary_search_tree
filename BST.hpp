
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
class BST
{
private:
    // BST Node
    struct Node
    {
        T data;
        Node* left;
        Node* right;

        Node(T value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    // Insert a node
    Node* insertNode(Node* node, T value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

    // Search for a value
    bool searchNode(Node* node, T value) const
    {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return searchNode(node->left, value);

        return searchNode(node->right, value);
    }

    // Find minimum node
    Node* findMinimum(Node* node)
    {
        while (node != nullptr && node->left != nullptr)
            node = node->left;

        return node;
    }

    // Delete a node
    Node* deleteNode(Node* node, T value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Case 1: No left child
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: No right child
            if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMinimum(node->right);

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // In-order traversal
    void inOrder(Node* node) const
    {
        if (node == nullptr)
            return;

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Pre-order traversal
    void preOrder(Node* node) const
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order traversal
    void postOrder(Node* node) const
    {
        if (node == nullptr)
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    // Free allocated memory
    void destroyTree(Node* node)
    {
        if (node == nullptr)
            return;

        destroyTree(node->left);
        destroyTree(node->right);

        delete node;
    }

public:
    // Constructor
    BST()
    {
        root = nullptr;
    }

    // Destructor
    ~BST()
    {
        destroyTree(root);
    }

    // Public insertion
    void insert(T value)
    {
        root = insertNode(root, value);
    }

    // Public search
    bool search(T value) const
    {
        return searchNode(root, value);
    }

    // Public deletion
    void remove(T value)
    {
        root = deleteNode(root, value);
    }

    // Public traversals
    void displayInOrder() const
    {
        inOrder(root);
        cout << endl;
    }

    void displayPreOrder() const
    {
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() const
    {
        postOrder(root);
        cout << endl;
    }
};

#endif
