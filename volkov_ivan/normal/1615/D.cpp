#include <bits/stdc++.h>
//#define int long long

using namespace std;

struct edge {
    int v, u, w;
    edge() {}
    edge(int v, int u, int w): v(v), u(u), w(w) {}
};

const int N = 2e5 + 7;
vector <pair <int, bool>> g[N];
vector <pair <int, int>> gg[N];
vector <edge> glob_ans;
int color[N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        gg[i].clear();
        color[i] = -1;
    }
    glob_ans.clear();
}

bool dfs0(int v, int cl) {
    color[v] = cl;
    for (auto [u, c] : g[v]) {
        if (color[u] == -1) {
            if (!dfs0(u, c ^ cl))
                return 0;
        } else {
            if (color[u] != (c ^ cl))
                return 0;
        }
    }
    return 1;
}

void dfs(int v, int pr = -1) {
    for (auto [u, w] : gg[v]) {
        if (u == pr)
            continue;

        if (w != -1) {
            assert(__builtin_popcount(w) % 2 == (color[v] ^ color[u]));
            glob_ans.push_back(edge(v, u, w));
        } else {
            glob_ans.push_back(edge(v, u, color[v] ^ color[u]));
        }
        
        dfs(u, v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        gg[x].push_back({y, v});
        gg[y].push_back({x, v});
        if (v != -1) {
            int c = __builtin_popcount(v) % 2;
            g[x].push_back({y, c});
            g[y].push_back({x, c});
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        g[a].push_back({b, p});
        g[b].push_back({a, p});
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!dfs0(i, 0)) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    dfs(1);
    cout << "YES\n";
    for (auto elem : glob_ans) {
        cout << elem.v << ' ' << elem.u << ' ' << elem.w << "\n";
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}