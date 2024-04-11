#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200005;
int lz[maxn<<2], mx[maxn<<2];
inline void upd(int rt, int l, int r, ll v) {
    mx[rt] += v;
    lz[rt] += v;
}
inline void pushdown(int rt, int l, int r) {
    int m = (l + r) >> 1;
    if(lz[rt]) {
        upd(rt << 1, l, m, lz[rt]);
        upd(rt << 1 | 1, m + 1, r, lz[rt]);
        lz[rt] = 0;
    }
}
void update(int L,int R,int v,int l,int r,int rt) {
    if(L <= l && r <= R) {
        upd(rt, l, r, v);
        return;
    }
    pushdown(rt, l, r);
    int m = (l + r) >> 1;
    if(m >= L) update(L,R,v,l,m,rt<<1);
    if(m < R) update(L,R,v,m+1,r,rt<<1|1);
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        vector<int> pa(n);
        for(int i = 1; i < n; ++i) pa[i] = pa[i-1] + a[i];
        memset(lz, 0, sizeof(int)*4*(n+1));
        memset(mx, 0, sizeof(int)*4*(n+1));
        for(int i = 1; i < n; ++i) update(i, i, pa[i], 0, n-1, 1);
        int ans = mx[1];
        for(int i = 0; i < n - 1; ++i) {
            update(i + 1, n - 1, -a[i+1], 0, n-1, 1);
            update(0, i, b[i], 0, n-1, 1);
            ans = min(ans, mx[1]);
        }
        cout << ans << endl;
    }
}