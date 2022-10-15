#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
struct CtrlZ {
    stack<pair<T&, T>> stk;
    void save(T& x) { stk.emplace(x, x); }
    void rollback() {
        stk.top().first = stk.top().second;
        stk.pop();
    }
};

struct DSU {
    CtrlZ<int> ctrlz;
    vector<int> p, rk;
    DSU(int n) : p(n), rk(n) { iota(all(p), 0); }
    int find(int u) { return p[u] == u ? u : find(p[u]); }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rk[u] < rk[v]) swap(u, v);
        ctrlz.save(p[v]);
        ctrlz.save(rk[u]);
        p[v] = u, rk[u] += (rk[u] == rk[v]);
        return true;
    }
    void rollback() {
        ctrlz.rollback();
        ctrlz.rollback();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> edges(m);
    vector<int> w(m);

    for (int j = 0; j < m; ++j) {
        auto& [u, v] = edges[j];
        cin >> u >> v >> w[j];
        --u, --v;
    }

    int q;
    cin >> q;

    vector<int> k(q);
    map<int, set<int>> check;
    vector<map<int, vector<int>>> C(q);

    for (int z = 0; z < q; ++z) {
        cin >> k[z];
        for (int l = 0; l < k[z]; ++l) {
            int j;
            cin >> j;
            --j;
            C[z][w[j]].push_back(j);
            check[w[j]].insert(z);
        }
    }

    vector<int> J(m);
    iota(all(J), 0);
    sort(all(J), [&](int j1, int j2){ return w[j1] < w[j2]; });

    DSU dsu(n);
    int last = -1;
    for (auto j : J) {
        if (last != w[j]) {
            last = w[j];
            for (auto z : check[w[j]]) {
                int cnt = 0;
                for (auto l : C[z][w[j]]) {
                    auto [u, v] = edges[l];
                    if (dsu.unite(u, v)) cnt += 1;
                }
                k[z] -= cnt;
                for (int i = 0; i < cnt; ++i) dsu.rollback();
            }
        }
        auto [u, v] = edges[j];
        dsu.unite(u, v);
    }

    for (int z = 0; z < q; ++z) {
        string ans = k[z] == 0 ? "YES" : "NO";
        cout << ans << endl;
    }


    exit(0);
}