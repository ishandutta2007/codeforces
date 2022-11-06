#pragma GCC optimize("Ofast", "no-stack-protector", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define getchar gtx

inline int gtx() {
    const int N = 4096;
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
    char c = 0; bool flag = false;
    while (c = getchar(), (c < '0' && c != '-') || c > '9') if (c == -1) return false;
    c == '-' ? (flag = true, x = 0) : (x = c - '0');
    while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 3e5 + 5;
const long long inf = 1e18;
vector<pair<int, int>> g[maxn];
int fa[maxn];
long long d1[maxn], dn[maxn], far[maxn];
bool on[maxn], ori;

void dfs(int x, int p, long long d, long long *v) {
    v[x] = d;
    fa[x] = p;
    for (auto u : g[x]) if (u.first != p)
        dfs(u.first, x, d + u.second, v);
}

long long dfs2(int x, int p, long long d) {
    long long res = d;
    int ch = 0;
    for (auto u : g[x]) if (u.first != p && !on[u.first])
        ch++, res = max(res, dfs2(u.first, x, d + u.second));
    if (p == 0 && ch > 1) ori = true;
    return res;
}

int main() {
    int n, m; rit(n, m);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, w; rit(x, y, w);
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    dfs(1, 0, 0, d1);
    vector<int> pt;
    int x = n;
    while (true) {
        pt.push_back(x);
        if (x == 1) break;
        x = fa[x];
    }
    dfs(n, 0, 0, dn);
    for (int i = 0; i < pt.size(); ++i) on[pt[i]] = true;
    for (int i = 0; i < pt.size(); ++i) far[pt[i]] = dfs2(pt[i], 0, 0);
    long long all = d1[n], cmax = 0;
    set<pair<long long, int>> s;
    pair<long long, int> pr[2] = { make_pair(-inf, -1), make_pair(-inf, -1) };
    for (int i = 0; i < pt.size(); ++i) {
        int z = 0;
        if (pr[0].second != -1) {
            int x = pr[0].second;
            if (far[x] == 0 && far[pt[i]] == 0 && pt[i - 1] == x) ++z;
            cmax = max(d1[pt[i]] + far[pt[i]] + pr[z].first, cmax);
        }
        if (dn[pt[i]] + far[pt[i]] > pr[0].first) pr[1] = pr[0], pr[0] = make_pair(dn[pt[i]] + far[pt[i]], pt[i]);
        else if (dn[pt[i]] + far[pt[i]] > pr[1].first) pr[1] = make_pair(dn[pt[i]] + far[pt[i]], pt[i]);
    }
    while (m--) {
        int x; rit(x);
        if (ori) printf("%lld\n", d1[n]);
        else printf("%lld\n", min(d1[n], d1[n] + cmax - all + x));
    }
    return 0;
}