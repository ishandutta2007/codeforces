#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int sz[maxn], a[maxn], b[maxn], c[maxn];
vector<int> G[maxn];

void dfs(int now, int fa) {
    sz[now] = 1;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        sz[now] += sz[u];
    }
}

long double cal(long long v, int n) { return (long double)(v * 6) / (long double)(n * 1ll * (n - 1)); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }
    dfs(1, 0);
    long long now = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (sz[a[i]] > sz[b[i]]) swap(a[i], b[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        now += c[i] * 1ll * sz[a[i]] * (n - sz[a[i]]);
    }
    int q; cin >> q; while (q--) {
        int r, w; cin >> r >> w; --r;
        now -= c[r] * 1ll * sz[a[r]] * (n - sz[a[r]]);
        c[r] = w;
        now += c[r] * 1ll * sz[a[r]] * (n - sz[a[r]]);
        cout << fixed << setprecision(20) << cal(now, n) << endl;
    }
    return 0;
}