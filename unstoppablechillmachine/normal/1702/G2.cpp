#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 2e5 + 10;
const int L = 19;
vector<int> g[N];
int up[L][N], h[N], tin[N], tout[N], timer;

void dfs(int v, int parent = 0, int curh = 0) {
    tin[v] = ++timer;
    h[v] = curh;
    up[0][v] = (parent ? parent : v);
    for (int i = 1; i < L; i++) {
        up[i][v] = up[i - 1][up[i - 1][v]];
    }

    for (auto u : g[v]) {
        if (u != parent) {
            dfs(u, v, curh + 1);
        }
    }
    tout[v] = ++timer;
}

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int u, int v) {
    if (anc(u, v)) {
        return u;
    }
    for (int i = L - 1; i >= 0; i--) {
        if (!anc(up[i][u], v)) {
            u = up[i][u];
        }
    }
    return up[0][u];
}

int go_up(int v, int d) {
    for (int i = 0; i < L; i++) {
        if ((d >> i) & 1) {
            v = up[i][v];
        }
    }
    return v;
}

int dist(int a, int b) {
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin >> n;
        timer = 0;
        for (int i = 1; i <= n; i++) {
            g[i] = {};
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int cnt;
            cin >> cnt;
            //cout << cnt << endl;
            vector<int> v(cnt);
            for (auto &x : v) {
                cin >> x;
            }
            int lc = v[0];
            for (int j = 1; j < cnt; j++) {
                lc = lca(lc, v[j]);
            }
            sort(v.begin(), v.end(), [&](int V, int U) {
                return h[V] > h[U];
            });
            int V = v[0], U = 0;
            for (int j = 1; j < cnt; j++) {
                if (go_up(v[j], h[v[j]] - h[lc] - 1) != go_up(v[0], h[v[0]] - h[lc] - 1)) {
                    U = v[j];
                    break;
                }
            }
            bool ok = true;
            for (auto it : v) {
                if (dist(it, V) + dist(it, lc) != dist(V, lc) && (!U || dist(it, U) + dist(it, lc) != dist(U, lc))) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}