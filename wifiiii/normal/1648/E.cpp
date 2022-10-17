#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define D(...)
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
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int,int,int>> es(m);
        vector<set<int>> g(n);
        for(auto &[w, u, v] : es) {
            cin >> u >> v >> w, --u, --v;
            g[u].insert(v);
            g[v].insert(u);
        }
        auto pes = es;
        ufind uf1(n);
        sort(es.begin(), es.end());
        vector<vector<vector<int>>> a(n);
        for(int i = 0; i < n; ++i) {
            a[i].push_back({i});
        }
        ufind uf2(n);
        vector<vector<pair<int,int>>> G(n);
        for(auto [w, u, v] : es) {
            D("!", w, u, v);
            if(!uf1.same(u, v)) {
                u = uf1.find(u), v = uf1.find(v);
                if(a[u].size() > a[v].size()) swap(u, v);
                int lid = 0;
                vector<vector<int>> mg(a[v].size());
                D(a[u], a[v]);
                for(auto &l : a[u]) {
                    int rid = 0, msz = 0, mid = -1;
                    vector<int> mark(a[v].size());
                    vector<vector<int>> nav(1), nmg(1);
                    for(auto &r : a[v]) {
                        int f = 0;
                        for(int i : l) {
                            for(int j : r) {
                                if(!g[i].count(j)) {
                                    // merge l, r
                                    D(w, i, j, "!!!");
                                    D(lid, rid);
                                    assert(uf2.merge(i,j));
                                    G[i].push_back({j, w});
                                    G[j].push_back({i, w});
                                    if(r.size() > msz) {
                                        mid = rid;
                                        msz = r.size();
                                    }
                                    mark[rid] = 1;
                                    f = 1;
                                    break;
                                }
                            }
                            if(f) break;
                        }
                        ++rid;
                    }
                    if(mid != -1) {
                        swap(nav[0], a[v][mid]);
                        swap(nmg[0], mg[mid]);
                        nmg[0].push_back(lid);
                        for(int k = 0; k < a[v].size(); ++k) {
                            if(mark[k]) {
                                if(k != mid) {
                                    for(int r : a[v][k]) nav[0].push_back(r);
                                    for(int r : mg[k]) nmg[0].push_back(r);
                                }
                            } else {
                                nav.push_back(move(a[v][k]));
                                nmg.push_back(move(mg[k])); // ?
                            }
                        }
                        D(nav);
                        D(nmg);
                        swap(a[v], nav);
                        swap(mg, nmg);
                    }
                    ++lid;
                }
                D(mg);
                vector<vector<int>> na;
                vector<int> used(a[u].size());
                D(a[v]);
                for(int i = 0; i < a[v].size(); ++i) {
                    int msz = a[v][i].size(), mid = -1;
                    for(int j : mg[i]) {
                        used[j] = 1;
                        if(a[u][j].size() > msz) {
                            msz = a[u][j].size();
                            mid = j;
                        }
                    }
                    if(mid == -1) {
                        na.push_back(move(a[v][i]));
                        for(int j : mg[i]) {
                            for(int k : a[u][j]) {
                                na.back().push_back(k);
                            }
                        }
                    } else {
                        na.push_back(move(a[u][mid]));
                        for(int j : mg[i]) {
                            if(j != mid)
                            for(int k : a[u][j]) {
                                na.back().push_back(k);
                            }
                        }
                        for(int k : a[v][i]) {
                            na.back().push_back(k);
                        }
                    }
                }
                for(int i = 0; i < a[u].size(); ++i) {
                    if(!used[i]) {
                        na.push_back(move(a[u][i]));
                    }
                }
                D(na);
                uf1.par[v] = u;
                swap(na, a[u]);
            }
        }
        assert(uf2.size(0)==n);
        vector<vector<int>> mx(n, vector<int>(19)), f(n, vector<int>(19, -1));
        vector<int> dep(n);
        function<void(int,int)> dfs = [&](int u, int fa) {
            for(auto [v, w] : G[u]) {
                if(v == fa) continue;
                f[v][0] = u;
                mx[v][0] = w;
                dep[v] = dep[u] + 1;
                for(int i = 1; i <= 18; ++i) {
                    if(f[v][i - 1] == -1) break;
                    f[v][i] = f[f[v][i - 1]][i - 1];
                    mx[v][i] = max(mx[v][i - 1], mx[f[v][i - 1]][i - 1]);
                }
                dfs(v, u);
            }
        };
        dfs(0, -1);
        auto solve = [&](int u, int v) {
            if(dep[u] > dep[v]) swap(u, v);
            int ret = 0;
            for(int i = 18, d = dep[v] - dep[u]; i >= 0; --i) {
                if(d >> i & 1) {
                    ret = max(ret, mx[v][i]);
                    v = f[v][i];
                }
            }
            if(u == v) return ret;
            for(int i = 18; i >= 0; --i) {
                if(f[u][i] != -1 && f[u][i] != f[v][i]) {
                    ret = max(ret, mx[v][i]);
                    ret = max(ret, mx[u][i]);
                    u = f[u][i];
                    v = f[v][i];
                }
            }
            ret = max(ret, mx[u][0]);
            ret = max(ret, mx[v][0]);
            return ret;
        };
        for(auto [w, u, v] : pes) {
            cout << solve(u, v) << ' ';
        }
        cout << '\n';
    }
}