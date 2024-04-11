#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
struct Trie {
    Trie* left;
    Trie* right;
    int cnt;
    
};
Trie* init() {
    Trie* ret = new Trie();
    ret->left = nullptr;
    ret->right = nullptr;
    ret->cnt = 0;
    return ret;
}
void insert(int x, Trie* root) {
    Trie* curr = root;
    if(curr==nullptr) {
        curr = init();
    }
    for(int i=29;i>=0;i--){
        if(x&(1<<i)) {
            if(curr->right==nullptr)
                curr->right = init();
            curr = curr->right;
        }
        else {
            if(curr->left==nullptr)
                curr->left = init();
            curr = curr->left;
        }
        ++curr->cnt;
    }
}
int query(int x, Trie* root) {
    Trie* curr = root;
    if(curr==nullptr) {
        curr = init();
    }
    int ret = 0;
    for(int i=29;i>=0;i--) {
        if(x&(1<<i)) {
            if(curr->left==nullptr || curr->left->cnt==0) {
                curr = curr->right;
            }
            else {
                ret+=1<<i;
                curr = curr->left;
            }
        }
        else {
            if(curr->right==nullptr || curr->right->cnt==0) {
                curr = curr->left;
            }
            else {
                ret+=1<<i;
                curr = curr->right;
            }
        }
    }
    return ret;
}
void remove(int x,Trie* root) {
    Trie* curr = root;
    if(curr==nullptr) {
        curr = init();
    }
    for(int i=29;i>=0;i--) {
        if(x&(1<<i)) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
        --curr->cnt;
    }
}
int main(){
    int q; cin >> q;
    Trie* head = init();
    insert(0,head);
    while(q--){
        char c;
        int x;
        cin >> c >> x;
        if(c=='+'){
            insert(x,head);
        }
        else if(c=='-') {
            remove(x,head);
        }
        else {
            cout << query(x,head) << "\n";
        }
    }
}