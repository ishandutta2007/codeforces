#include <bits/stdc++.h>
using namespace std;

const int maxn = 123456;
vector<int> graf[maxn];
int bst, dis, sz[maxn];
bool am[maxn], kp[maxn];

void dfs(int now, int fa, int d) {
    if (d > dis) bst = now, dis = d;
    else if (d == dis) bst = min(bst, now);
    for (int u : graf[now]) if (u != fa && sz[u] > 0) dfs(u, now, d + 1);
}

void dfssz(int now, int tar, int fa) {
    if (now == tar) kp[now] = true;
    if (am[now]) ++sz[now];
    for (int u : graf[now]) if (u != fa) {
        dfssz(u, tar, now);
        sz[now] += sz[u];
        if (kp[u]) kp[now] = true;
    }
}

long long dfsans(int now, int fa) {
    long long ret = 0;
    for (int u : graf[now]) if (u != fa) {
        if (sz[u] == 0) continue;
        if (kp[u]) ret += dfsans(u, now) + 1;
        else ret += dfsans(u, now) + 2;
    }
    return ret;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        --a; --b;
        graf[a].push_back(b); graf[b].push_back(a);
    }
    int rt = -1;
    for (int i = 0; i < m; ++i) {
        int u; scanf("%d", &u); --u;
        am[u] = true;
        rt = u;
    }
    if (m == 1) {
        printf("%d\n%d\n", rt + 1, 0);
        return 0;
    }
    dfssz(rt, 0, -1); dfs(rt, -1, 0);
    int uv = bst;
    memset(sz, 0, sizeof(sz)); 
    dis = 0; dfssz(uv, 0, -1); dfs(uv, -1, 0);
    int vu = bst;
    rt = min(uv, vu);
    int ort = max(uv, vu);
    memset(sz, 0, sizeof(sz)); memset(kp, false, sizeof(kp));
    dfssz(rt, ort, -1);
    printf("%d\n%lld\n", rt + 1, dfsans(rt, -1));
    return 0;
}