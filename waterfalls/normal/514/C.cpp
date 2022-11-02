#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    map<char,Node*> adj;
    bool ending;
};

class Trie {
private:
    Node* head;
    string query;
public:
    Trie() { head = new Node(); head->ending = false; }
    void addWord(string text) {
        Node* cur = head;
        for (int i=0;i<text.size();i++) {
            if (!cur->adj.count(text[i])) {
                Node* child = new Node();
                child->ending = false;
                cur->adj[text[i]] = child;
            }
            cur = cur->adj[text[i]];
        }
        cur->ending = true;
    }
    bool search(string q) {
        query = q;
        return isearch(head,0,0);
    }
    bool isearch(Node* cur, int where, int remain) {
        if (remain>=2) return false;
        if (where==query.size()) return cur->ending && remain!=0;
        if (cur->adj.count('a') && isearch(cur->adj['a'],where+1,remain+('a'!=query[where]))) return true;
        if (cur->adj.count('b') && isearch(cur->adj['b'],where+1,remain+('b'!=query[where]))) return true;
        if (cur->adj.count('c') && isearch(cur->adj['c'],where+1,remain+('c'!=query[where]))) return true;
        return false;
    }
};

int n,m;
Trie trie;
string text;
string query;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> text, trie.addWord(text);
    for (int i=0;i<m;i++) cin >> query, cout << (trie.search(query) ? "YES" : "NO") << "\n";

    return 0;
}