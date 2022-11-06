#include <bits/stdc++.h>
using namespace std;

struct Subgroup {
    vector<int> member;
};

pair<map<vector<int>, int>, vector<vector<int>>> Build(int k) {
    vector<int> p(k);
    iota(p.begin(), p.end(), 0);
    map<vector<int>, int> mp;
    vector<vector<int>> res;
    int sz = 0;
    do { 
        mp[p] = sz++; 
        res.push_back(p);
    } while (next_permutation(p.begin(), p.end()));
    return make_pair(mp, res);
}

vector<int> Multiply(const vector<int> &a, const vector<int> &b) {
    const int k = a.size();
    vector<int> res(k);
    for (int i = 0; i < k; ++i) res[i] = b[a[i]];
    return res;
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<vector<int>> p(n, vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &p[i][j]);
            p[i][j]--;
        }
    }
    auto [kMap, kPerm] = Build(k);
    const int m = kPerm.size();
    vector<vector<int>> to(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            vector<int> v = Multiply(kPerm[i], kPerm[j]);
            to[i][j] = kMap[v];
        }
    }
    // for (int i = 0; i < m; ++i) {
        // for (int j = 0; j < m; ++j) printf("%d ", to[i][j]);
        // puts("");
    // }

    auto Insert = [&](vector<int> sub, int v) {
        // printf("Insert v = %d\n", v);
        // for (int u : sub) printf("%d ", u);
        // puts("");
        vector<int> vis(m);
        for (int u : sub) vis[u] = 1;
        if (vis[v]) return sub;
        queue<int> q;
        q.push(v);
        vis[v] = 1;
        sub.push_back(v);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            vector<int> ps;
            for (int u : sub) {
                assert(x < m && u < m);
                int y = to[x][u];
                assert(y < m);
                if (!vis[y]) {
                    vis[y] = 1;
                    ps.push_back(y);
                    q.push(y);
                }
                y = to[u][x];
                assert(y < m);
                if (!vis[y]) {
                    vis[y] = 1;
                    ps.push_back(y);
                    q.push(y);
                }
            }
            for (int p : ps) sub.push_back(p);
        }
        sort(sub.begin(), sub.end());
        return sub;
    };

    queue<vector<int>> q;
    q.push({0});
    map<vector<int>, int> smp;
    vector<vector<int>> sg;
    smp[{0}] = 0;
    sg.push_back({0});
    while (!q.empty()) {
        auto sub = q.front(); q.pop();
        for (int i = 0; i < m; ++i) {
            auto nsub = Insert(sub, i);
            if (smp.find(nsub) == smp.end()) {
                int id = smp.size();
                sg.push_back(nsub);
                smp[nsub] = id;
                q.push(nsub);
            }
        }
    }
    // for (auto sub : sg) {
        // for (int u : sub) printf("%d ", u);
        // puts("");
    // }
    const int z = sg.size();
    vector<vector<int>> sto(z, vector<int>(z));
    vector<vector<int>> sub(z, vector<int>(z));

    auto MergeSub = [&](int i, int j) {
        vector<int> s = sg[i];
        for (int u : sg[j]) s = Insert(s, u);
        return smp[s];
    };

    auto CheckSub = [&](int i, int j) {
        vector<int> used(m);
        for (int u : sg[i]) used[u] = 1;
        int f = 1;
        for (int u : sg[j]) if (!used[u]) f = 0;
        if (!f) return 0;
        if (sg[i].size() > sg[j].size()) f = 2;
        return f;
    };

    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < z; ++j) {
            sto[i][j] = MergeSub(i, j);
            sub[i][j] = CheckSub(i, j);
        }
    }
    vector<int> sig(m);
    for (int i = 0; i < m; ++i) {
        vector<int> b = kPerm[i];
        vector<int> ss;
        while (true) {
            ss.push_back(kMap[b]);
            if (b == kPerm[0]) break;
            b = Multiply(b, kPerm[i]);
        }
        sort(ss.begin(), ss.end());
        assert(smp.find(ss) != smp.end());
        sig[i] = smp[ss];
    }
    vector<vector<int>> sp(1, vector<int>(n));
    for (int i = 0; i < n; ++i) sp[0][i] = sig[kMap[p[i]]];
    // for (int i = 0; i < n; ++i) {
        // printf("%d : %d\n", sp[0][i], (int)sg[sp[0][i]].size());
    // }
    for (int i = 1; (1 << i) <= n; ++i) {
        sp.emplace_back(n);
        for (int j = 0; j + (1 << i) <= n; ++j) {
            sp[i][j] = sto[sp[i - 1][j]][sp[i - 1][j + (1 << (i - 1))]];
        }
    }

    auto Query = [&](int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return sto[sp[p][l]][sp[p][r - (1 << p) + 1]];
    };
    // for (int i = 0; i < z; ++i) {
        // for (int j = 0; j < z; ++j) printf("%d ", sub[i][j]);
        // puts("");
    // }

    long long ans = 0;
    for (int i = 0; i < z; ++i) {
        int lp = -1, rp = -1;
        int mut = sg[i].size();
        for (int j = 0; j < n; ++j) {
            while (lp + 1 <= j) {
                int k = Query(lp + 1, j);
                // printf("Query l = %d r = %d res = %d\n", lp + 1, j, k);
                if (sub[k][i]) lp++;
                else break;
            }
            while (rp + 1 <= j) {
                int k = Query(rp + 1, j);
                if (sub[k][i] == 2) rp++;
                else break;
            }
            // printf("i = %d j = %d lp = %d rp = %d\n", i, j, lp, rp);
            ans += 1LL * mut * (lp - rp);
        }
    }
    printf("%lld\n", ans);
    return 0;
}