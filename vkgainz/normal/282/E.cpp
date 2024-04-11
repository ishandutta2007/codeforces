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
void insert(ll x, Trie* root) {
    Trie* curr = root;
    if(curr==nullptr) {
        curr = init();
    }
    for(int i=39;i>=0;i--){
        if(x&(1LL<<i)) {
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
ll query(ll x, Trie* root) {
    Trie* curr = root;
    if(curr==nullptr) {
        curr = init();
    }
    ll ret = 0;
    for(int i=39;i>=0;i--) {
        if(x&(1LL<<i)) {
            if(curr->left==nullptr || curr->left->cnt==0) {
                curr = curr->right;
            }
            else {
                ret+=1LL<<i;
                curr = curr->left;
            }
        }
        else {
            if(curr->right==nullptr || curr->right->cnt==0) {
                curr = curr->left;
            }
            else {
                ret+=1LL<<i;
                curr = curr->right;
            }
        }
    }
    return ret;
}
void remove(ll x,Trie* root) {
    Trie* curr = root;
    if(curr==nullptr) {
        curr = init();
    }
    for(int i=39;i>=0;i--) {
        if(x&(1LL<<i)) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
        --curr->cnt;
    }
}
int main(){
    int n; cin >> n;
    ll a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    ll s[n];
    s[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--) s[i] = s[i+1]^a[i];
    Trie* head = new Trie();
    for(int i=0;i<n;i++) insert(s[i],head);
    insert(0,head);
    ll p = 0;
    ll ans = query(0,head);
    for(int i=0;i<n;i++) {
        p^=a[i];
        remove(s[i],head);
        ans = max(ans,query(p,head));
    }
    cout << ans << endl;
}