#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int seg[400000][20];
int lazy[400000];
int sz = 1;
void prop(int x,int lx,int rx) {
    if(lazy[x]==0) return;
    for(int bit=0;bit<20;bit++) {
        if(lazy[x]&(1<<bit)) {
            seg[x][bit] = rx-lx-seg[x][bit];
        }
    }
    if(rx-lx!=1) {
        lazy[2*x+1]^=lazy[x];
        lazy[2*x+2]^=lazy[x];
    }
    lazy[x] = 0;
}
void upd(int l,int r,int v, int x=0,int lx=0, int rx=sz) {
    prop(x,lx,rx);
    if(lx>=r || rx<=l) return;
    if(lx>=l && rx<=r) {
        for(int bit=0;bit<20;bit++) {
            if(v&(1<<bit)) {
                seg[x][bit] = rx-lx-seg[x][bit];
            }
        }
        if(rx-lx!=1) {
            lazy[2*x+1]^=v;
            lazy[2*x+2]^=v;
        }
        return;
    }
    int m = (lx+rx)/2;
    upd(l,r,v,2*x+1,lx,m), upd(l,r,v,2*x+2,m,rx);
    for(int bit=0;bit<20;bit++) seg[x][bit] = seg[2*x+1][bit]+seg[2*x+2][bit];
}
ll query(int l,int r,int x=0, int lx=0, int rx=sz) {
    prop(x,lx,rx);
    if(lx>=r || rx<=l) return 0;
    if(lx>=l && rx<=r) {
        ll ret = 0;
        for(int bit=0;bit<20;bit++) {
            ret+=(1LL<<bit)*1LL*seg[x][bit];
        }
        return ret;
    }
    int m = (lx+rx)/2;
    return query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx);
}
void build(vector<int> &a, int x=0,int lx=0, int rx=sz) {
    if(rx-lx==1) {
        if(lx<a.size()) {
            for(int bit=0;bit<20;bit++) {
                if(a[lx]&(1<<bit)) seg[x][bit] = 1;
            }
        }
    }
    else {
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m), build(a,2*x+2,m,rx);
        for(int bit=0;bit<20;bit++) {
            seg[x][bit] = seg[2*x+1][bit]+seg[2*x+2][bit];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(sz<n) sz*=2;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    build(a);
    int m; cin >> m;
    while(m--) {
        int t; cin >> t;
        if(t==1) {
            int l,r; cin >> l >> r;
            --l;
            cout << query(l,r) << endl;
        }
        else {
            int l,r,x; cin >> l >> r >> x;
            --l;
            upd(l,r,x);
        }
    }
}