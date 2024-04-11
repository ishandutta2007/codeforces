#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    bool ending;
    map<char,Node*> adj;
};

class Trie {
private:
    Node* head;
    string word;
    void addWordI(Node* which, int where) {
        if (where==word.size()) which->ending = true;
        else {
            which->ending = false;
            if (!which->adj.count(word[where])) {
                Node* next = new Node();
                next->ending = false;
                which->adj[word[where]] = next;
            }
            addWordI(which->adj[word[where]],where+1);
        }
    }
public:
    Trie() { head = new Node(); head->ending = false; }
    void addWord(string w) { word = w; addWordI(head,0); }
    const Node* getHead() { return head; }
};

bool dfs(const Node* x) {
    for (map<char,Node*>::const_iterator it=x->adj.begin();it!=x->adj.end();it++) if (!dfs(it->second)) return true;
    return false;
}

bool dfs2(const Node* x) {
    if (x->ending) return true;
    for (map<char,Node*>::const_iterator it=x->adj.begin();it!=x->adj.end();it++) if (!dfs2(it->second)) return true;
    return false;
}

int n,k;
Trie trie;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        string next;
        cin >> next;
        trie.addWord(next);
    }
    if (dfs(trie.getHead())) {
        if (dfs2(trie.getHead())) cout << "First\n";
        else {
            if (k%2==0) cout << "Second\n";
            else cout << "First\n";
        }
    } else cout << "Second\n";

    return 0;
}