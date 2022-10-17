#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int w, id;
    bool operator < (const node & n) const {
        return w > n.w || (w == n.w && id > n.id);
    }
};
const int maxn = 200005;
ll mn[maxn<<2], lz[maxn<<2];
inline void upd(int rt, ll v) {
    mn[rt] += v;
    lz[rt] += v;
}
void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        upd(rt, v);
        return;
    }
    if(lz[rt]) {
        upd(rt<<1, lz[rt]);
        upd(rt<<1|1, lz[rt]);
        lz[rt] = 0;
    }
    int m = (l + r) / 2;
    if(L <= m) update(L, R, v, l, m, rt<<1);
    if(m < R) update(L, R, v, m+1, r, rt<<1|1);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
ll query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return mn[rt];
    if(lz[rt]) {
        upd(rt<<1, lz[rt]);
        upd(rt<<1|1, lz[rt]);
        lz[rt] = 0;
    }
    ll ret = 1e18;
    int m = (l + r) / 2;
    if(L <= m) ret = min(ret, query(L, R, l, m, rt<<1));
    if(m < R) ret = min(ret, query(L, R, m+1, r, rt<<1|1));
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<node> b(n);
    for(int i = 0; i < n; ++i) cin >> a[i], b[i] = {a[i], i};
    sort(b.begin(), b.end());
    int ret = 0;
    for(auto x : b) {
        if(query(x.id, n-1, 0, n-1, 1) + x.w < 0) continue;
        update(x.id, n-1, x.w, 0, n-1, 1);
        ret += 1;
    }
    cout << ret << '\n';
}

/*
8
4 -4 4 -4 1 -3 1 -3
 */