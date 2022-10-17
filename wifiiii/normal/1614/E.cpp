#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 6e5+5;
int tot=0;
int ls[maxn*32],rs[maxn*32],sum[maxn*32],mx[maxn*32],mn[maxn*32];
void newnode(int &o, int l, int r) {
    o=++tot;mx[o]=r,mn[o]=l;
}
void pushdown(int o, int l, int r) {
    int m=(l+r)/2;
    if(!ls[o]) newnode(ls[o],l,m); if(!rs[o]) newnode(rs[o],m+1,r);
    sum[ls[o]] += sum[o], sum[rs[o]] += sum[o];
    mx[ls[o]] += sum[o], mx[rs[o]] += sum[o];
    mn[ls[o]] += sum[o], mn[rs[o]] += sum[o];
    sum[o]=0;
}
void update(int &o,int val,int L,int R,int l,int r) {
    if(!o) newnode(o,l,r);
    if(L<=l && r<=R) {
        sum[o]+=val;
        mx[o]+=val;
        mn[o]+=val;
        return;
    }
    pushdown(o,l,r);
    int m=(l+r)/2;
    if(L<=m) update(ls[o],val,L,R,l,m);
    if(m<R) update(rs[o],val,L,R,m+1,r);
    mn[o]=min(mn[ls[o]],mn[rs[o]]);
    mx[o]=max(mx[ls[o]],mx[rs[o]]);
}
int query(int o,int p,int l,int r) {
    if(l==r) return mn[o];
    pushdown(o,l,r);
    int m=(l+r)/2;
    if(p<=m) return query(ls[o],p,l,m);
    return query(rs[o],p,m+1,r);
}
int findL(int o,int v,int l,int r) {
    if(l==r) {
        if(mn[o]<=v) return l;
        return -1;
    }
    pushdown(o,l,r);
    int m=(l+r)/2;
    if(mn[rs[o]]<=v) return findL(rs[o],v,m+1,r);
    return findL(ls[o],v,l,m);
}
int findR(int o,int v,int l,int r) {
    if(l==r) {
        if(mx[o]>=v) return l;
        return -1;
    }
    pushdown(o,l,r);
    int m=(l+r)/2;
    if(mx[ls[o]]>=v) return findR(ls[o],v,l,m);
    return findR(rs[o],v,m+1,r);
}
const int N = 1e9;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int lastans = 0, rt = 0;
    newnode(rt, 0, N);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int l = findL(rt, x - 1, 0, N), r = findR(rt, x + 1, 0, N);
        if(l != -1) update(rt, 1, 0, l, 0, N);
        if(r != -1) update(rt, -1, r, N, 0, N);
        int t;
        cin >> t;
        while(t--) {
            int y;
            cin >> y;
            y = (y + lastans) % (N + 1);
            lastans = query(rt, y, 0, N);
            cout << lastans << '\n';
        }
    }
}