#pragma GCC optimize("Ofast", "no-stack-protector", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

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

const int maxn = 2e6 + 5;
vector<int> ds, res[maxn];
int n, a[maxn][2];
int fa[maxn], ec[maxn], sz[maxn];
int qu[maxn];
bool used[maxn], done[maxn];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        ec[i] = 0;
        sz[i] = 1;
    }
}

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
        ++ec[x];
        return;
    }
    fa[x] = y;
    ec[y] += ec[x] + 1;
    sz[y] += sz[x];
}

bool check(int t) {
    for (int i = 0; i <= t; ++i) used[i] = false;
    for (int i = 0; i < n; ++i) done[i] = false;
    function<int(int)> opt = [t](int x) {
        int ret = 0;
        for (int i = 0; i < 2; ++i)
            ret += !used[a[x][i]] && a[x][i] <= t;
        return ret;
    };
    int ql = 0, qr = 0;
    for (int i = 0; i < n; ++i) {
        int o = opt(i);
        if (o == 0) return false;
        if (o == 1) qu[qr++] = i;
    }
    while (ql < qr) {
        int x = qu[ql++];
        if (opt(x) == 0) return false;
        int y = -1;
        for (int i = 0; i < 2; ++i)
            if (!used[a[x][i]] && a[x][i] <= t) y = a[x][i];
        used[y] = true;
        done[x] = true;
        for (int u : res[y]) {
            if (done[u]) continue;
            if (opt(u) == 1) qu[qr++] = u;
        }
    }
    init(ds.size());
    for (int i = 0; i < n; ++i) if (!done[i]) {
        assert(a[i][0] <= t && !used[a[i][0]]);
        assert(a[i][1] <= t && !used[a[i][1]]);
        merge(a[i][0], a[i][1]);
    }
    for (int i = 0; i < n; ++i) if (!done[i]) {
        int p = find(i);
        if (ec[p] > sz[p]) return false;
    }
    return true;
} 

int main() {
    rit(n);
    for (int i = 0; i < n; ++i) {
        rit(a[i][0], a[i][1]);
        ds.push_back(a[i][0]);
        ds.push_back(a[i][1]);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) for (int j = 0; j < 2; ++j)
        a[i][j] = lower_bound(ds.begin(), ds.end(), a[i][j]) - ds.begin();
    for (int i = 0; i < n; ++i) for (int j = 0; j < 2; ++j)
        res[a[i][j]].push_back(i);
    int d = 30, ans = ds.size();
    while (d--) if (ans - (1 << d) >= 0) 
        if (check(ans - (1 << d))) ans -= (1 << d);
    if (ans == ds.size()) puts("-1");
    else printf("%d\n", ds[ans]);
    return 0;
}