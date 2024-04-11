#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    Node * parent_;
    vector<Node *> children_;
    long long number_, additions_, subtractions_;
    Node() {
      parent_ = NULL;
      children_ = vector<Node *>();
      number_ = 0ll;
      additions_ = 0ll;
      subtractions_ = 0ll;
    }
};

class ZeroTreeSolver {
  private:
    vector<Node> nodes_;

  public:
    ZeroTreeSolver() {
      nodes_ = vector<Node>();
    }

    void ReadTree() {
      int node_number;
      cin >> node_number;
      nodes_.resize(node_number);
      for (int i = 1; i < node_number; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        nodes_[from].children_.push_back(&nodes_[to]);
        nodes_[to].children_.push_back(&nodes_[from]);
      }
      for (int i = 0; i < node_number; i++) {
        cin >> nodes_[i].number_;
      }
    }

    void EvaluateNode(Node * node) {
      for (auto child: node->children_) {
        if (child != node->parent_) {
          child->parent_ = node;
          EvaluateNode(child);
          node->additions_ = max(node->additions_, child->additions_);
          node->subtractions_ = max(node->subtractions_, child->subtractions_);
        }
      }
      node->number_ += node->additions_;
      node->number_ -= node->subtractions_;
      if (node->number_ > 0) {
        node->subtractions_ += node->number_;
      } else {
        node->additions_ -= node->number_;
      }
    }

    long long EvaluateTree() {
      EvaluateNode(&nodes_[0]);
      return nodes_[0].additions_ + nodes_[0].subtractions_;
    }
};

// To execute C++, please define "int main()"
int main() {
  ZeroTreeSolver solver = ZeroTreeSolver();
  solver.ReadTree();
  cout << solver.EvaluateTree() << endl;
  return 0;
}

/*
Test case #1:
3
1 2
1 3
1 -1 1

Answer: 3

Test case #2:
4
2 1
3 2
4 3
1 -2 3 -4

Answer: 19
*/