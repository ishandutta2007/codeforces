#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000;
vector<int> g[kN], nd;
int a[kN], sz[kN], mk[kN];
bool v[kN];

void DfsSz(int x) {
    nd.push_back(x);
    v[x] = true;
    sz[x] = 1;
    mk[x] = 0;
    for (int u : g[x]) {
        if (!v[u]) {
            DfsSz(u);
            sz[x] += sz[u];
            mk[x] = max(mk[x], sz[u]);
        }
    }
}

struct Data {
    int depth;
    long long sum;
    long long pref;

    Data() : depth(0), sum(0), pref(0) {}
    Data(int d, long long s, long long p) : depth(d), sum(s), pref(p) {}

    Data Prepend(int v) const {
        return Data(depth + 1, sum + v, pref + sum + v);
    }
};

void DfsPath(int x, int p, int d, long long s, long long t, vector<Data> &vk) {
    s += a[x];
    t += 1LL * d * a[x];
    vk.emplace_back(d, s, t);
    for (int u : g[x]) {
        if (u == p || v[u]) continue;
        DfsPath(u, x, d + 1, s, t, vk);
    }
}

void DfsRevPath(int x, int p, int d, long long s, long long t, vector<Data> &vk) {
    s += a[x];
    t += s;
    vk.emplace_back(d, s, t);
    for (int u : g[x]) {
        if (u == p || v[u]) continue;
        DfsRevPath(u, x, d + 1, s, t, vk);
    }
}

struct Line {
    mutable int64_t a, b, p;
    bool operator<(const Line &rhs) const { return a < rhs.a; }
    bool operator<(int64_t x) const { return p < x; }
};

struct DynamicHull : multiset<Line, less<>> {
    static const int64_t kInf = 1e18;
    int64_t Div(int64_t a, int64_t b) { return a / b - ((a ^ b) < 0 && a % b); }
    bool Isect(iterator x, iterator y) {
        if (y == end()) { x->p = kInf; return false; }
        if (x->a == y->a) x->p = x->b > y->b ? kInf : -kInf;
        else x->p = Div(y->b - x->b, x->a - y->a);
        return x->p >= y->p;
    }
    void Insert(int64_t a, int64_t b) {
        auto z = insert({a, b, 0}), y = z++, x = y;
        while (Isect(y, z)) z = erase(z);
        if (x != begin() && Isect(--x, y)) Isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) Isect(x, erase(y));
    }
    int64_t Query(int64_t x) {
        auto l = *lower_bound(x);
        return l.a * x + l.b; 
    }
};

long long Solve(int x) {
    vector<vector<Data>> ch = {{Data()}}, chv = ch;
    for (int u : g[x]) {
        if (!v[u]) {
            vector<Data> v, w;
            DfsPath(u, x, 1, 0, 0, v);
            DfsRevPath(u, x, 1, 0, 0, w);
            ch.push_back(v);
            chv.push_back(w);
        }
    }
    long long res = 0;
    for (int it = 0; it < 2; ++it) {
        DynamicHull hull;
        for (int i = 0; i < ch.size(); ++i) {
            if (!hull.empty()) {
                for (auto &d : ch[i]) {
                    auto pd = d.Prepend(a[x]);
                    int64_t v = hull.Query(pd.sum);
                    res = max(res, pd.pref + v);
                }
            }
            for (auto &d : chv[i]) {
                int64_t a = d.depth;
                int64_t b = d.pref;
                hull.Insert(a, b);
            }
        }
        reverse(ch.begin(), ch.end());
        reverse(chv.begin(), chv.end());
    }
    return res;
}

long long Dfs(int x, int p) {
    nd.clear();
    DfsSz(x);
    int m = (int)nd.size(), c = -1;
    for (int u : nd) {
        if (max(mk[u], m - sz[u]) * 2 <= m) c = u;
        v[u] = false;
    }
    long long res = Solve(c);
    v[c] = true;
    for (int u : g[c]) {
        if (!v[u]) res = max(res, Dfs(u, c));
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("%lld\n", Dfs(0, -1));
    return 0;
}