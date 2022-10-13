#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;

struct Trie {
    Trie *left, *right;
    int num;
};
Trie* getNew() {
    Trie *ret = new Trie;
    ret->left = nullptr;
    ret->right = nullptr;
    ret->num = 0;
    return ret;
}
void insert(Trie* head, int x) {
    Trie *curr = head;
    for(int bit=30;bit>=0;bit--) {
        if(x&(1<<bit)) {
            if(curr->right==nullptr)
                curr->right = getNew();
            curr = curr->right;
            ++curr->num;
        }
        else {
            if(curr->left==nullptr)
                curr->left = getNew();
            curr = curr->left;
            ++curr->num;
        }
    }
}
int getDP(Trie* curr) {
    if(curr->left==nullptr && curr->right==nullptr) {
        return 0;
    }
    if(curr->left==nullptr) return getDP(curr->right);
    if(curr->right==nullptr) return getDP(curr->left);
    return min(curr->left->num+getDP(curr->right), curr->right->num+getDP(curr->left))-1;
}
int main() {
    int n; cin >> n;
    int a[n];
    Trie* head = getNew();
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) insert(head, a[i]);
    cout << getDP(head);

}