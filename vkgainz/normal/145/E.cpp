#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
    int f, s, li, ld;
    Node(int a,int b,int c,int d) {
        f = a, s = b, li = c, ld = d;
    }
    Node() {
        f = 0, s = 0, li = 0, ld = 0;
    }
};
int sz = 1;
Node merge(Node a, Node b) { //checkt his?
    Node ret = Node();
    ret.f = a.f+b.f;
    ret.s = a.s+b.s;
    ret.li = max(a.li+b.s, a.f+b.li);
    ret.ld = max(a.ld+b.f, a.s+b.ld);
    return ret;
}
Node flip(Node x) {
    return Node(x.s, x.f, x.ld, x.li);
}
string s;
Node seg[4000000+5];
bool lazy[4000000+5];
void build(int x=0, int lx=0, int rx=sz) {
    if(rx-lx==1) {
        if(lx<s.length()) {
            if(s[lx]=='4') seg[x] = Node(1,0,1,1);
            else seg[x] = Node(0,1,1,1);
        }
        else seg[x] = Node();
    }
    else {
        int m = (lx+rx)/2;
        build(2*x+1,lx,m), build(2*x+2,m,rx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }
}
void prop(int x,int lx,int rx) {
    if(lazy[x]) {
        seg[x] = flip(seg[x]);
        if(rx-lx!=1) {
            lazy[2*x+1] = 1-lazy[2*x+1];
            lazy[2*x+2] = 1-lazy[2*x+2];
        }
    }
    lazy[x] = 0;
}
void upd(int l, int r,int x=0, int lx=0, int rx=sz) {
    prop(x,lx,rx);
    if(lx>=r || rx<=l) return;
    if(lx>=l && rx<=r) {
        seg[x] = flip(seg[x]);
        if(rx-lx!=1) {
            lazy[2*x+1] = 1-lazy[2*x+1];
            lazy[2*x+2] = 1-lazy[2*x+2];
        }
        return;
    }
    int m = (lx+rx)/2;
    upd(l,r,2*x+1,lx,m), upd(l,r,2*x+2,m,rx);
    seg[x] = merge(seg[2*x+1], seg[2*x+2]);
}
int query() {
    prop(0,0,sz);
    return seg[0].li;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    while(sz<n) sz*=2;
    cin >> s;
    build();
    vector<int> ans;
    while(m--) {
        string t; cin>> t;
        if(t=="switch") {
            int l, r; cin >> l >> r;
            --l;
            upd(l,r);
        }
        else ans.push_back(query());
    }
    for(auto &it : ans) cout << it << "\n";
}