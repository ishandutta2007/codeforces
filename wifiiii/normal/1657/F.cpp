#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct lcatree {
    int n, lg;
    vector<vector<int>> f, g;
    vector<int> dep;
    lcatree(vector<vector<int>> g): g(g) {
        n = g.size();
        lg = 32 - __builtin_clz(n);
        f.resize(lg, vector<int>(n, -1));
        dep.resize(n);
    }
    void dfs(int u, int fa) {
        for(int v : g[u]) {
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            f[0][v] = u;
            dfs(v, u);
        }
    }
    int lca(int u, int v) {
        if(dep[u] < dep[v]) swap(u, v);
        for(int d = dep[u] - dep[v], i = lg - 1; i >= 0; --i) {
            if(d >> i & 1) u = f[i][u];
        }
        if(u == v) return u;
        for(int i = lg - 1; i >= 0; --i) {
            if(f[i][u] != -1 && f[i][u] != f[i][v]) {
                u = f[i][u], v = f[i][v];
            }
        }
        return f[0][u];
    }
    void init(int s) {
        assert(0 <= s && s < n);
        dfs(s, -1);
        for(int i = 1; i < lg; ++i) {
            for(int j = 0; j < n; ++j) {
                f[i][j] = f[i - 1][j] == -1 ? -1 : f[i - 1][f[i - 1][j]];
            }
        }
    }
};

struct constraint {
    char l, r;
    int id;
};
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lcatree lca(g);
    lca.init(0);
    vector<vector<constraint>> cs(n);
    vector<vector<int>> ap(q);
    vector<string> as(q);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        string s;
        cin >> s;
        int x = lca.lca(l, r);
        vector<int> p {l};
        while(l != x) {
            l = lca.f[0][l];
            p.push_back(l);
        }
        vector<int> ss;
        while(r != x) {
            ss.push_back(r);
            r = lca.f[0][r];
        }
        while(!ss.empty()) {
            p.push_back(ss.back());
            ss.pop_back();
        }
        ap[i] = p;
        as[i] = s;
        assert(p.size() == s.size());
        for(int j = 0; j < p.size(); ++j) {
            char L = s[j], R = s[s.size() - 1 - j];
            cs[p[j]].push_back({L, R, i});
            // cout << p[j] << ' ' << L << ' ' << R << ' ' << i << endl;
        }
    }
    vector<int> par(2 * q + 2);
    int T = 2 * q, F = 2 * q + 1;
    for(int i = 0; i < par.size(); ++i) par[i] = i;
    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    };
    for(int u = 0; u < n; ++u) {
        char l = 0, r = 0;
        int i = -1;
        // cout << u << ": " << endl;
        for(auto [L, R, id] : cs[u]) {
            // cout << "(" << l << " " << r << " " << i << "), " << "(" << L << " " << R << " " << id << ")" << endl;
            if(L == R) {
                if(l == 0) {
                    l = r = L;
                } else if(l == L || r == R) {
                    if(i != -1) {
                        if(l == L) {
                            par[find(i)] = find(T);
                            par[find(i + q)] = find(F);
                        } else {
                            par[find(i + q)] = find(T);
                            par[find(i)] = find(F);
                        }
                        l = r = L; i = -1;
                    } else {
                        l = r = L; i = -1;
                    }
                } else {
                    cout << "NO\n";
                    return 0;
                }
                continue;
            }
            if(l == 0) {
                i = id;
                l = L;
                r = R;
            } else if(i == -1) {
                if(l != L && r != R) {
                    cout << "NO\n";
                    return 0;
                }
                if(l == L) {
                    par[find(id)] = find(T);
                    par[find(id + q)] = find(F);
                } else {
                    par[find(id + q)] = find(T);
                    par[find(id)] = find(F);
                }
            } else {
                if(L != l && R != r && L != r && R != l) {
                    cout << "NO\n";
                    return 0;
                }
                if((L == l && R == r) || (L == r && R == l)) {
                    if(L == l) {
                        par[find(i)] = find(id);
                        par[find(i + q)] = find(id + q);
                    } else {
                        par[find(i + q)] = find(id);
                        par[find(i)] = find(id + q);
                    }
                } else if(L == l || R == r || L == r || R == l) {
                    char res = 0;
                    if(L == l) res = l;
                    if(R == r) res = r;
                    if(L == r) res = L;
                    if(R == l) res = R;
                    assert(res != 0);
                    if(l == res) {
                        par[find(i)] = find(T);
                        par[find(i + q)] = find(F);
                    } else {
                        par[find(i)] = find(F);
                        par[find(i + q)] = find(T);
                    }
                    if(L == res) {
                        par[find(id)] = find(T);
                        par[find(id + q)] = find(F);
                    } else {
                        par[find(id)] = find(F);
                        par[find(id + q)] = find(T);
                    }
                }
            }
        }
    }
    string ans(n, 'a');
    for(int i = 0; i < q; ++i) {
        if(find(i) == find(i + q)) {
            cout << "NO\n";
            return 0;
        }
        if(find(i) == find(T)) {
            for(int j = 0; j < as[i].size(); ++j) {
                ans[ap[i][j]] = as[i][j];
            }
        } else {
            par[find(i + q)] = find(T);
            par[find(i)] = find(F);
            reverse(as[i].begin(), as[i].end());
            for(int j = 0; j < as[i].size(); ++j) {
                ans[ap[i][j]] = as[i][j];
            }
        }
    }
    cout << "YES\n";
    cout << ans << '\n';
}