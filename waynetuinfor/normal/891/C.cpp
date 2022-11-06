#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 5e5 + 10;
vector<int> edge;
vector<pair<int, int>> G[maxn];
int a[maxn], b[maxn], c[maxn], ans[maxn], tin[maxn], low[maxn], t;
int na[maxn], nb[maxn];
bool v[maxn];

stack<int> eid;

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

struct dsu {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { p[find(x)] = find(y); }
} dsu;

struct DisjointSet {
    int p[maxn], sz[maxn], n;
    vector<pair<int*, int>> h;
    vector<int> sp;
    void init(int size) {
        n = size;
        for (int i = 0; i < n; ++i) p[i] = i, sz[i] = 1;
        sp.clear(); h.clear();
    }
    void assign(int *k, int v) {
        h.push_back(make_pair(k, *k));
        *k = v;
    }
    void save() {
        sp.push_back(h.size());
    }
    void undo() {
        int last = sp.back(); sp.pop_back();
        while (h.size() != last) {
            pair<int*, int> pi = h.back(); h.pop_back();
            *pi.first = pi.second;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        assign(&sz[x], sz[x] + sz[y]);
        assign(&p[y], x);
    }
} djs;

void dfs(int now) {
    tin[now] = low[now] = ++t;
    for (auto u : G[now]) if (!v[u.second]) {
        v[u.second] = true;
        eid.push(u.second);
        if (tin[u.first]) {
            low[now] = min(low[now], tin[u.first]);
            continue;
        }
        dfs(u.first);
        low[now] = min(low[now], low[u.first]);
        if (low[u.first] > tin[now]) {
            ans[u.second] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; rit(n, m);
    for (int i = 0; i < m; ++i) {
        rit(a[i], b[i], c[i]);
        edge.push_back(i);
    }
    sort(edge.begin(), edge.end(), [&](const int &i, const int &j) { return c[i] < c[j]; });
    dsu.init();
    fill(ans, ans + maxn, -1);
    for (size_t i = 0; i < edge.size(); ) {
        size_t ptr = i;
        while (ptr < edge.size() && c[edge[ptr]] == c[edge[i]]) {
            int u = dsu.find(a[edge[ptr]]), v = dsu.find(b[edge[ptr]]);
            if (u == v) ans[edge[ptr]] = 0;
            else G[u].emplace_back(v, edge[ptr]), G[v].emplace_back(u, edge[ptr]), na[edge[ptr]] = u, nb[edge[ptr]] = v;
            ++ptr;
        }
        for (size_t j = i; j < ptr; ++j) {
            if (!v[edge[j]]) {
                dfs(dsu.find(a[edge[j]]));
            }
        }
        for (size_t j = i; j < ptr; ++j) {
            int u = dsu.find(a[edge[j]]), v = dsu.find(b[edge[j]]);
            tin[u] = low[u] = tin[v] = low[v] = 0;
            G[u].clear(); G[v].clear();
            dsu.merge(u, v);
        }
        i = ptr;
    } 
    int q; rit(q);
    djs.init(maxn);
    while (q--) {
        int k; rit(k);
        bool ok = true;
        vector<int> ed;
        for (int i = 0; i < k; ++i) {
            int p; rit(p); --p;
            ed.push_back(p);
        }
        sort(ed.begin(), ed.end(), [&](const int &i, const int &j) { return c[i] < c[j]; });
        for (int i = 0; i < k; ) {
            int p = i;
            djs.save();
            while (p < k && c[ed[p]] == c[ed[i]]) {
                if (ans[ed[p]] == 0) ok = false;
                else if (ans[ed[p]] != 1) {
                    if (djs.find(na[ed[p]]) == djs.find(nb[ed[p]])) ok = false;
                    djs.merge(na[ed[p]], nb[ed[p]]);
                }
                ++p;
            }
            djs.undo();
            i = p;
        }
        if (!ok) puts("NO");
        else puts("YES");
    }
    return 0;
}