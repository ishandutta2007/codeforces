#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 1e5 + 7;
vector <int> g[N];
int deg[N];
bool alive[N];

long long to_num(int v, int u) {
    if (v > u) swap(v, u);
    return 1ll * N * v + u;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        deg[i] = 0;
        alive[i] = 1;
    }
    set <pair <int, int>> verts;
    unordered_set <long long> edges;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        deg[v]++;
        deg[u]++;
        g[v].push_back(u);
        g[u].push_back(v);
        edges.insert(to_num(v, u));
    }
    for (int i = 1; i <= n; i++) {
        verts.insert({deg[i], i});
    }
    while (!verts.empty()) {
        auto [dg, v] = *verts.begin();
        verts.erase(verts.begin());
        alive[v] = 0;
        if (dg >= k) {
            vector <int> res;
            for (auto elem : verts) {
                res.push_back(elem.second);
            }
            res.push_back(v);
            cout << 1 << ' ' << res.size() << "\n";
            for (int elem : res) cout << elem << ' ';
            cout << "\n";
            return;
        }
        if (dg == k - 1) {
            vector <int> clique;
            clique.push_back(v);
            for (int u : g[v]) {
                if (alive[u]) {
                    clique.push_back(u);
                }
            }
            assert((int) clique.size() == k);
            bool flag = 1;
            for (int i = 0; i < k; i++) {
                for (int j = i + 1; j < k; j++) {
                    if (edges.find(to_num(clique[i], clique[j])) == edges.end()) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (flag) {
                cout << 2 << "\n";
                for (int elem : clique) cout << elem << ' ';
                cout << "\n";
                return;
            }
        }
        for (int u : g[v]) {
            if (!alive[u])
                continue;
            verts.erase({deg[u], u});
            deg[u]--;
            verts.insert({deg[u], u});
        }
    }
    cout << "-1" << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}