#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 2e5 + 10;
vector<pair<int, int>> g[N], g2[N];
int cl[N];
bool used[N], ok;

void set_color(int v, int color) {
    assert(color == 0 || color == 1);
    if (cl[v] == -1) {
        cl[v] = color;
    } else if (cl[v] != color) {
        ok = false;
    }
}

void dfs2(int v, int color) {
    used[v] = true;
    set_color(v, color);
    for (auto u : g2[v]) {
        if (!used[u.F]) {
            dfs2(u.F, color ^ u.S);
        } else if ((color ^ u.S) != cl[u.F]) {
            ok = false;
        }
    }
}

vector<pair<int, pair<int, int>>> edges;

void dfs(int v, int p = 0, int color = 0) {
    for (auto u : g[v]) {
        if (u.F == p) {
            continue;
        }
        if (u.S != -1) {
            edges.pb({u.S, {v, u.F}});
        } else {
            if (cl[u.F] != color) {
                edges.pb({1, {v, u.F}});
            } else {
                edges.pb({0, {v, u.F}});
            }
        }
        dfs(u.F, v, cl[u.F]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        ok = true;
        for (int i = 1; i <= n; i++) {
            g[i] = {};
            g2[i] = {};
            cl[i] = -1;
            used[i] = false;
        }
        edges = {};
        cl[1] = 0;
        for (int i = 1; i < n; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            if (u > v) {
                swap(u, v);
            }
            if (c != -1) {
                if (u == 1) {
                    set_color(v, __builtin_popcount(c) % 2);
                } else {
                    g2[u].pb({v, __builtin_popcount(c) % 2});
                    g2[v].pb({u, __builtin_popcount(c) % 2});
                }
            }

            g[u].pb({v, c});
            g[v].pb({u, c});
        }
        for (int i = 1; i <= m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            if (u > v) {
                swap(u, v);
            }
            if (u == 1) {
                set_color(v, c);
            } else {
                g2[v].pb({u, c});
                g2[u].pb({v, c});
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i] && cl[i] != -1) {
                dfs2(i, cl[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs2(i, 0);
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        dfs(1);
        cout << "YES\n";
        for (auto it : edges) {
            cout << it.S.F << ' ' << it.S.S << ' ' << it.F << '\n';
        }
    }
}