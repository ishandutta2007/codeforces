#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct VectorSpace {
    bool trivial;
    uint32_t mask;
    vector<int> basis;

    VectorSpace() : trivial(true), mask(0) {}

    bool Insert(int v) {
        for (int u : basis) v = min(v, v ^ u);
        if (v == 0) {
            trivial = false;
            return false;
        } else {
            mask |= (1U << v);
            basis.push_back(v);
            return true;
        }
    }

    VectorSpace Merge(const VectorSpace &rhs) const {
        vector<int> all(basis.begin(), basis.end());
        all.insert(all.end(), rhs.basis.begin(), rhs.basis.end());
        sort(all.begin(), all.end());
        VectorSpace res;
        res.trivial = trivial && rhs.trivial;
        for (int u : all) res.Insert(u);
        return res;
    }

    bool Independent(const VectorSpace &rhs) const {
        return Merge(rhs).trivial;
    }

    bool Equivalent(const VectorSpace &rhs) const {
        if (basis.size() != rhs.basis.size()) return false;
        for (int u : rhs.basis) {
            for (int k : basis) u = min(u, k ^ u);
            if (u > 0) return false;
        }
        for (int u : basis) {
            for (int k : rhs.basis) u = min(u, k ^ u);
            if (u > 0) return false;
        }
        return true;
    }

    bool operator==(const VectorSpace &rhs) const {
        return mask == rhs.mask;
    }

    bool operator<(const VectorSpace &rhs) const {
        return mask < rhs.mask;
    }
};

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());

    vector<int> used(n), sum(n), dep(n);

    auto Insert = [&](auto &bs, int v) {
        for (int u : bs) v = min(v, u ^ v);
        if (v > 0) bs.push_back(v);
    };

    vector<int> visited;
    function<VectorSpace(int, int, int, int)> Dfs = [&](int x, int p, int a, int b) {
        dep[x] = dep[p] + 1;
        used[x] = 1;
        VectorSpace vs;
        visited.push_back(x);
        for (auto [u, w] : g[x]) {
            if (u == p || u == 0 && (a == x || b == x)) continue;
            if (used[u]) {
                if (dep[u] > dep[x]) continue;
                int v = sum[x] ^ sum[u] ^ w;
                vs.Insert(v);
            } else {
                sum[u] = sum[x] ^ w;
                vs = vs.Merge(Dfs(u, x, a, b));
            }
        }
        return vs;
    };

    vector<vector<VectorSpace>> vs;
    for (auto [u, x] : g[0]) {
        int kv = -1, ed = -1;
        for (auto [v, y]  : g[u]) {
            if (g[v][0].first == 0) {
                kv = v;
                ed = y;
            }
        }
        if (kv == -1) {
            sum[u] = 0;
            vs.push_back({VectorSpace(), Dfs(u, 0, u, -1)});
        } else {
            if (u > kv) continue;
            vector<VectorSpace> vk(4);
            for (int s = 0; s < 4; ++s) {
                used[0] = 1;
                int a = (s & 1) ? u : -1;
                int b = (s >> 1 & 1) ? kv : -1;
                if (!(s & 1)) {
                    if (!used[u]) {
                        sum[u] = sum[0] ^ x;
                        vk[s] = vk[s].Merge(Dfs(u, 0, a, b));
                    }
                }
                if (!(s >> 1 & 1)) {
                    if (!used[kv]) {
                        sum[kv] = sum[0] ^ ed;
                        vk[s] = vk[s].Merge(Dfs(kv, 0, a, b));
                    }
                }
                for (int r : visited) used[r] = 0;
                visited.clear();
                used[0] = 0;
            }
            vs.push_back(vk);
        }
    }

    vector<int> ids;
    vector<VectorSpace> ds, rv;

    auto BuildIndepSets = [&]() {
        function<void(int, int, VectorSpace)> Rec = [&](int i, int j, VectorSpace v) {
            rv.push_back(v);
            if (i == 32 || j == 5) return;
            Rec(i + 1, j, v);
            if (v.Insert(i)) Rec(i + 1, j + 1, v);
        };
        Rec(0, 0, VectorSpace());
        sort(rv.begin(), rv.end());
        rv.resize(unique(rv.begin(), rv.end()) - rv.begin());
        ids.resize(rv.size(), -1);
        for (int i = 0; i < rv.size(); ++i) {
            bool ok = true;
            int k = -1;
            for (int j = 0; k == -1 && j < i; ++j) {
                if (rv[i].Equivalent(rv[j])) k = j;
            }
            if (k != -1) ids[i] = ids[k];
            else ids[i] = ds.size(), ds.push_back(rv[i]);
        }
        return ids;
    };

    auto GetID = [&](const VectorSpace &v) {
        int p = lower_bound(rv.begin(), rv.end(), v) - rv.begin();
        return ids[p];
    };

    BuildIndepSets();
    vector<vector<int>> id;
    for (auto &vk : vs) {
        vector<int> vp;
        for (auto &v : vk) vp.push_back(GetID(v));
        id.push_back(vp);
    }
    constexpr int kMod = 1'000'000'000 + 7;
    const int kM = ds.size();
    vector<vector<int>> mg(kM, vector<int>(kM));
    vector<vector<int>> to(kM, vector<int>(kM));
    for (int i = 0; i < kM; ++i) {
        for (int j = 0; j < kM; ++j) {
            mg[i][j] = ds[i].Independent(ds[j]);
            if (!mg[i][j]) continue;
            to[i][j] = GetID(ds[i].Merge(ds[j]));
        }
    }
    vector<int> prv(kM);
    prv[GetID(VectorSpace())] = 1;
    for (int i = 0; i < vs.size(); ++i) {
        vector<int> nxt(kM);
        for (int j = 0; j < vs[i].size(); ++j) {
            if (vs[i][j].trivial) {
                for (int k = 0; k < kM; ++k) {
                    if (mg[id[i][j]][k]) (nxt[to[id[i][j]][k]] += prv[k]) %= kMod;
                }
            }
        }
        nxt.swap(prv);
    }
    int ans = 0;
    for (int i = 0; i < kM; ++i) {
        ans += prv[i];
        if (ans >= kMod) ans -= kMod;
    }
    printf("%d\n", ans);
    return 0;
}