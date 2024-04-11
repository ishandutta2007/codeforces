#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
vector <int> E[MAXN];
int lson[MAXN], ldep[MAXN], dep[MAXN], top[MAXN];
void dfs1 (int x, int fa) {
    dep[x] = dep[fa] + 1; ldep[x] = dep[x];
    for (auto i: E[x]) if (i != fa) {
        dfs1(i, x);
        if (ldep[i] > ldep[lson[x]]) lson[x] = i;
        ldep[x] = max(ldep[x], ldep[i] + 1);
    }
}

#define size(v) (int(v.size()))
vector <int> cur;
void dfs2 (int x, int fa) {
    if (lson[x]) top[lson[x]] = top[x], dfs2(lson[x], x);
    else cur.push_back(dep[x] - dep[top[x]] + 1);
    for (auto i: E[x]) if (i != fa && i != lson[x]) top[i] = i, dfs2(i, x);
}

int n, K;

int main () {
    n = read(), K = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs1(1, 0); top[1] = 1; dfs2(1, 0);
    sort(cur.begin(), cur.end()); reverse(cur.begin(), cur.end());
    cur.resize(n + 1);
    // for (auto i: cur) cout << i << ' '; cout << endl; // return 0;
    long long ans = -1e18; int pre = 0;
    for (i = 0; i < K; i++) {
        pre += cur[i]; int u = i + 1, v = n - pre;
        v = min(v, n >> 1);
        // printf("%d %d\n", u,v );
        // cout << 1ll * (n - u - v) * (u - v) << endl;
        ans = max(ans, 1ll * (n - u - v) * (u - v));
    }
    printf("%lld\n", ans);
    return 0;
}