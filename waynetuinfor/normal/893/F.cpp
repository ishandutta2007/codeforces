#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1, sq = 3000, lg = 20;
int a[maxn], d[maxn], t, tin[maxn], tout[maxn], c[maxn], e[maxn];
vector<int> G[maxn];

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }
void dfs(int now, int fa, int dep) {
    d[now] = dep;
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, dep + 1);
    }
    tout[now] = t;
}

struct sparse {
    vector<int> dat[lg];
    int n;
    void init(int _n, const vector<int> &arr) {
        for (int i = 0; i < lg; ++i) dat[i].resize(_n);
        n = _n;
        for (int i = 0; i < n; ++i) dat[0][i] = arr[i];
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
        }
    }
    int query(int l, int r) {
        l = max(0, l); r = min(r, n - 1);
        if (l > r) return inf;
        int p = 31 - __builtin_clz(r - l + 1);
        return min(dat[p][l], dat[p][r - (1 << p) + 1]);
    }
};

struct decomp {
    int minv[maxn], lb[maxn / sq + 10], rb[maxn / sq + 10], bid[maxn], sz[maxn / sq + 10];
    int mind[maxn / sq + 10], maxd[maxn / sq + 10];
    sparse sp[maxn / sq + 10];
    int n;
    inline void init(int _n) {
        n = _n;
        int blk = 0;
        for (int i = 1; i <= n; ) {
            ++blk;
            int j = 0;
            fill(minv, minv + maxn, inf);
            mind[blk] = inf;
            maxd[blk] = 0;
            while (j < sq && i + j <= n) {
                minv[e[i + j]] = min(minv[e[i + j]], c[i + j]);
                bid[i + j] = blk;
                mind[blk] = min(mind[blk], e[i + j]);
                maxd[blk] = max(maxd[blk], e[i + j]);
                ++j;
            }
            lb[blk] = i; rb[blk] = i + j - 1;
            i += j;
            sz[blk] = j;
            vector<int> vec;
            for (int j = mind[blk]; j <= maxd[blk]; ++j) vec.push_back(minv[j]);
            sp[blk].init(vec.size(), vec);
        }
    }
    inline int query(int l, int r, int p, int q) {
        if (bid[l] == bid[r]) {
            int ret = inf;
            for (int i = l; i <= r; ++i) {
                if (e[i] >= p && e[i] <= q) ret = min(ret, c[i]);
            }
            return ret;
        }
        int ret = inf;
        for (int b = bid[l] + 1; b < bid[r]; ++b) ret = min(ret, sp[b].query(p - mind[b], q - mind[b]));
        for (int i = l; i <= rb[bid[l]]; ++i) {
            if (e[i] >= p && e[i] <= q) ret = min(ret, c[i]);
        }
        for (int i = lb[bid[r]]; i <= r; ++i) {
            if (e[i] >= p && e[i] <= q) ret = min(ret, c[i]);
        }
        return ret;
    }
} solver;

int main() {
    int n, r; rit(n, r);
    for (int i = 1; i <= n; ++i) rit(a[i]);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; rit(a, b);
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(r, 0, 0);
    for (int i = 1; i <= n; ++i) c[tin[i]] = a[i];
    for (int i = 1; i <= n; ++i) e[tin[i]] = d[i];
    solver.init(n);
    int last = 0;
    int m; rit(m); while (m--) {
        int p, q; rit(p, q);
        int x = ((p + last) % n) + 1, k = (q + last) % n;
        last = solver.query(tin[x], tout[x], d[x], min(d[x] + k, n));
        printf("%d\n", last);
    }
    return 0;
}