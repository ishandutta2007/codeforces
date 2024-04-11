#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ufind {
    vector<int> par, sz;
    ufind(int n) : par(n), sz(n, 1) {
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    int find(int x) {
        if(x != par[x]) return par[x] = find(par[x]);
        return x;
    }
    int size(int x) {
        return sz[find(x)];
    }
    int same(int u, int v) {
        return find(u) == find(v);
    }
    int merge(int u, int v) {
        int x = find(u), y = find(v);
        if(x == y) return 0;
        if(sz[x] < sz[y]) swap(sz[x], sz[y]), swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return 1;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> es(m);
    for(auto &[w, u, v] : es) {
        cin >> u >> v >> w;
        --u, --v;
    }
    sort(es.begin(), es.end());
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<int> qs(k);
    for(int i = 0; i < p; ++i) cin >> qs[i];
    for(int i = p; i < k; ++i) qs[i] = (1ll * qs[i - 1] * a + b) % c;
    vector<int> ps {-1};
    for(int i = 0; i < m; ++i) {
        ps.push_back(get<0>(es[i]));
        ps.push_back(get<0>(es[i]) + 1);
        for(int j = i + 1; j < m; ++j) {
            ps.push_back((get<0>(es[i]) + get<0>(es[j]) + 1) / 2);
            ps.push_back((get<0>(es[i]) + get<0>(es[j]) + 1) / 2 + 1);
        }
    }
    sort(ps.begin(), ps.end());
    ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
    vector<int> ord(k);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return qs[i] < qs[j];});
    int j = 0;
    vector<int> ids;
    ll result = 0;
    for(int i : ord) {
        int x = qs[i], rebuild = 0;
        while(j < ps.size() && x >= ps[j]) {
            rebuild = 1;
            j += 1;
        }
        if(rebuild) {
            ids.clear();
            vector<int> orde(m);
            iota(orde.begin(), orde.end(), 0);
            sort(orde.begin(), orde.end(), [&](int i, int j) {return abs(x - get<0>(es[i])) < abs(x - get<0>(es[j]));});
            ufind uf(n);
            for(int r : orde) {
                auto [w, u, v] = es[r];
                if(uf.merge(u, v)) {
                    ids.push_back(r);
                }
            }
        }
        ll ans = 0;
        for(int r : ids) ans += abs(x - get<0>(es[r]));
        result ^= ans;
    }
    cout << result << '\n';
}