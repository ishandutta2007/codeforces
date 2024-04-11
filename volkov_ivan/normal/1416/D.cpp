#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 2e5 + 7, Q = 5e5 + 7;
vector <int> comp[N];
int color[N];
int sz[N], par[N];
int p[N];
vector <int> recolor[Q];
vector <pair <int, int>> e;
vector <int> tmdel;
set <int> comp2[2 * N];
int obr[N];

void merge(int v, int u, int t) {
    if (color[v] == color[u]) return;
    int clu = color[u], clv = color[v];
    if (sz[clu] > sz[clv]) {
        swap(u, v);
        swap(clu, clv);
    }
    sz[clv] += sz[clu];
    if (t != -1) recolor[t] = comp[clu];
    for (int elem : comp[clu]) {
        color[elem] = clv;
        comp[clv].push_back(elem);
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        obr[p[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        e.push_back({v, u});
        tmdel.push_back(-1);
    }
    vector <pair <int, int>> ask;
    for (int i = 0; i < q; i++) {
        int t, v;
        cin >> t >> v;
        ask.push_back({t, v});
        if (t == 2) tmdel[v - 1] = i;
    }
    for (int i = 1; i <= n; i++) {
        color[i] = i;
        comp[i].push_back(i);
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        if (tmdel[i] == -1) {
            merge(e[i].first, e[i].second, -1);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (ask[i].first == 2) {
            int p = ask[i].second - 1;
            int v = e[p].first, u = e[p].second;
            merge(v, u, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!comp[i].empty()) {
            for (int elem : comp[i]) {
                comp2[i].insert(p[elem]);
            }
        }
    }
    int lst = n + 1;
    for (int i = 0; i < q; i++) {
        if (ask[i].first == 1) {
            int ans;
            int cl = color[ask[i].second];
            if (comp2[cl].empty()) ans = 0;
            else {
                auto uk = comp2[cl].end();
                ans = *(--uk);
            }
            cout << ans << "\n";
            if (ans != 0) {
                int pos = obr[ans];
                p[pos] = 0;
                comp2[cl].erase(ans);
            }
        } else {
            if (!recolor[i].empty()) {
                for (int elem : recolor[i]) {
                    if (p[elem] != 0) {
                        comp2[color[elem]].erase(p[elem]);
                        comp2[lst].insert(p[elem]);
                        color[elem] = lst;
                    }
                    color[elem] = lst;
                }
                lst++;
            }
        }
    }
    return 0;
}