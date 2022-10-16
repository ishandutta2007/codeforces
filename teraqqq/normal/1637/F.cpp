#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int N = 2e5+7;

int n, h[N], tin[N], tout[N], rf[N], prv[N], e[N], gt, sgt[2*N], mxh;
ll ans, cur;
vector<int> g[N];

bool cmp(int i, int j) {
    return e[i] < e[j];
}

void sgt_upd(int i, int x) {
    cur += x - e[i];
    e[i] = x;
    i += n;
    for (; i != 1; i >>= 1) sgt[i >> 1] = max(sgt[i], sgt[i^1], cmp);
}

int sgt_max(int l, int r) {
    int ans = l;
    for (l += n, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if ((l&1) == 1) ans = max(ans, sgt[l++], cmp);
        if ((r&1) == 0) ans = max(ans, sgt[r--], cmp);
    }
    return ans;
}

void sgt_build() {
    iota(sgt+n, sgt+2*n, 0);
    for (int i = n; --i; ) sgt[i] = sgt[2*i];
}

void cancel(int v) {
    const int i = rf[v];
    if (i >= 0) {
        rf[v] = -1;
        sgt_upd(i, prv[v]);
    }
}

void make_link(int v, int i) {
    if (e[i] < h[v]) {
        prv[v] = e[i];
        rf[v] = i;
        sgt_upd(i, h[v]);
    }
}

void euler_tour(int v, int p = -1) {
    tin[v] = gt++;
    for (int to : g[v]) {
        if (to != p) euler_tour(to, v);
    }
    tout[v] = gt;

    make_link(v, sgt_max(tin[v], tout[v]));
}

void dfs(int v, int p = -1) {
    ans = min(ans, cur);

    for (int to : g[v]) {
        if (to == p) continue;

        cancel(v);
        cancel(to);
        make_link(v, max(sgt_max(0, tin[to]), sgt_max(tout[to], n), cmp));
        make_link(to, sgt_max(0, n));

        dfs(to, v);
        cancel(to);
        cancel(v);
        make_link(to, sgt_max(tin[to], tout[to]));
        make_link(v, sgt_max(0, n));
    }
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> h[i];
    mxh = *max_element(h, h+n);
    fill(rf, rf+n, -1);
    for (int i = n; --i; ) {
        int a, b; cin >> a >> b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cur = mxh;

    sgt_build();
    euler_tour(0);

    ans = 1e18;
    dfs(0);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}