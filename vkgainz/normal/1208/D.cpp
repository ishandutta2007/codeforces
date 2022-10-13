#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;
pair<ll, int> seg[4*MX];
ll lazy[4*MX];
int sz = 1;
pair<ll, int> merge(pair<ll, int> x, pair<ll, int> y) {
    if(x.f!=y.f) {
        if(x.f<y.f) return x;
        return y;
    }
    return {x.f, max(x.s,y.s)};
}
void prop(int x, int lx, int rx) {
    seg[x].f-=lazy[x];
    if(rx-lx!=1) {
        lazy[2*x+1]+=lazy[x];
        lazy[2*x+2]+=lazy[x];
    }
    lazy[x] = 0;
}
void upd(int l,int r, ll v, int x=0, int lx=0, int rx=sz) {
    prop(x, lx, rx);
    if(lx>=r || rx<=l) return;
    if(lx>=l && rx<=r) {
        seg[x].f-=v;
        if(rx-lx!=1) {
            lazy[2*x+1]+=v;
            lazy[2*x+2]+=v;
        }
        return;
    }
    int m = (lx+rx)/2;
    upd(l,r,v,2*x+1,lx,m), upd(l,r,v,2*x+2,m,rx);
    seg[x] = merge(seg[2*x+1], seg[2*x+2]);
}
void build(vector<ll> &c, int x=0, int lx=0, int rx=sz) {
    if(rx-lx==1) {
        if(lx<c.size()) seg[x] = {c[lx], lx};
        else seg[x] = {1e15,c.size()};
        return;
    }
    int m = (lx+rx)/2;
    build(c,2*x+1,lx,m), build(c,2*x+2,m,rx);
    seg[x] = merge(seg[2*x+1], seg[2*x+2]);
}
int cd = 1;
pair<ll, int> get(int l, int r,int x=0, int lx=0, int rx=sz) {
	prop(x, lx, rx);
	if(rx-lx==1) return seg[x];
    int m = (lx+rx)/2;
    prop(2*x+1, lx, m), prop(2*x+2, m, rx);
    if(seg[2*x+2].f<=seg[2*x+1].f) return get(l,r,2*x+2,lx,m);
    return get(l,r,2*x+1,m,rx);
}
int main() {
    int n; cin >> n;
    while(sz<n) sz*=2;
    vector<ll> c(n);
    for(int i=0;i<n;i++) {
        cin >> c[i];
    }
    build(c);
    int ans[n];
    for(int i=0;i<n;i++) {
        pair<ll, int> curr = get(0,n);
        ans[curr.s] = i+1;
        upd(curr.s, curr.s+1, -1e12);
        upd(curr.s+1, n, i+1);
    }
    for(int i=0;i<n;i++) cout << ans[i] << "\n";
}