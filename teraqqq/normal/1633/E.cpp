#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

struct Edge {
    int a, b, w;
};

struct Dsu {
    vector<int> p, c;

    Dsu(int n) : p(n), c(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    void clear() {
        fill(c.begin(), c.end(), 1);
        iota(p.begin(), p.end(), 0);
    } 

    int root(int v) {
        return v == p[v] ? v :  p[v] = root(p[v]);
    }

    bool unite(int a, int b) {
        a = root(a), b = root(b);
        if (a != b) {
            if (c[a] < c[b]) swap(a, b);
            p[b] = a;
            c[a] += c[b];
            return true;
        } else {
            return false;
        }
    }
};

void solve() {
    vector<int> uniqx { 0 };

    int n, m; cin >> n >> m;

    vector<Edge> edg(m);
    for (auto& [a, b, w] : edg) {
        cin >> a >> b >> w; --a, --b;
    }

    for (int i = 0; i < m; ++i)
    for (int j = 0; j < i; ++j) {
        if (edg[i].w == edg[j].w) continue;
        
        uniqx.push_back((edg[i].w + edg[j].w + 1) / 2);
    }
    
    sort(uniqx.begin(), uniqx.end());
    uniqx.erase(unique(uniqx.begin(), uniqx.end()), uniqx.end());

    vector<int> p(m);
    vector<vector<int>> ans;
    iota(p.begin(), p.end(), 0);
    Dsu dsu(n);

    for (int x : uniqx) {
        sort(p.begin(), p.end(), [&](int l, int r) {
            return make_pair(abs(edg[l].w - x), edg[r].w) < make_pair(abs(edg[r].w - x), edg[l].w);
        });

        dsu.clear();

        ans.emplace_back();
        for (int i : p) {
            if (dsu.unite(edg[i].a, edg[i].b)) ans.back().push_back(edg[i].w);
        }
    }

    ll res = 0;

    int p0, k, a, b, c; cin >> p0 >> k >> a >> b >> c;
    vector<int> q(k);

    for (int i = 0; i < p0; ++i) cin >> q[i];
    for (int i = p0; i < k; ++i) {
        q[i] = ((ll)q[i-1] * a + b) % c;
    }

    for (int x : q) {
        auto it = upper_bound(uniqx.begin(), uniqx.end(), x) - uniqx.begin() - 1;

        ll cost = 0;
        for (int w : ans[it]) cost += abs(w - x);
        res ^= cost;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    // cin >> t;
    while (t--) solve();
}