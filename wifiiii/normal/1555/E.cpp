#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int lz[maxn<<2],mn[maxn<<2];
inline void upd(int rt, int l, int r, ll v) {
    lz[rt] += v;
    mn[rt] += v;
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
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    --m;
    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
        --a[i][1];
    }
    sort(a.begin(), a.end(), [](auto i, auto j) {return i[2] < j[2];});
    int ans = 1e9;
    for(int i = 0, j = 0; i < n; ++i) {
        while(j < n && mn[1] == 0) {
            update(a[j][0], a[j][1], 1, 1, m, 1);
            ++j;
        }
        if(!mn[1]) break;
        ans = min(ans, a[j-1][2] - a[i][2]);
        update(a[i][0], a[i][1], -1, 1, m, 1);
    }
    cout << ans << '\n';
}