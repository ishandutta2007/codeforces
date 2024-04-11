#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define ll long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
int n, M;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % M;
        x = 1ll * x * x % M;
        y >>= 1;
    }
    return ret;
}
void exgcd (int a, int b, int &x, int &y) { if (!b) x = 1, y = 0; else exgcd(b, a % b, y, x), y -= (a / b) * x; }
int inv (int X) { int x, y; exgcd(X, M, x, y); return (x % M + M) % M; }

struct Edge { int nex, to, w; } edge[MAXN << 1];
int head[MAXN], cnt = 0;

void add (int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].nex = head[u];
    edge[cnt].w = w;
    head[u] = cnt;
}

int root, siz[MAXN], tans[MAXN] = {998244353}, sall;
bool vis[MAXN];

void getroot (int x, int f) {
    int i, j;
    siz[x] = 1, tans[x] = 0;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (j == f || vis[j]) continue;
        getroot(j, x); siz[x] += siz[j], tans[x] = max(tans[x], siz[j]);
    }
    tans[x] = max(tans[x], sall - siz[x]);
    if (tans[x] < tans[root]) root = x;
}

map <int, int> up;
int td = 0;

void dfs (int x, int f, int d, int tmpup, int k) {
    int i, j; tmpup = (tmpup % M + M) % M;
    up[tmpup] += k;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (j == f || vis[j]) continue;
        dfs(j, x, d + 1, (1ll * qpow(10, d) * edge[i].w % M + tmpup) % M, k);
    }
}

ll ans = 0;

void dfs2 (int x, int f, int tmpdown, int d) {
    int rua = (-1ll * tmpdown * inv(qpow(10, d)) % M + M) % M;
    ans += up[rua];
    int i, j;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (j == f || vis[j]) continue;
        dfs2(j, x, (1ll * tmpdown * 10 + edge[i].w) % M, d + 1);
    }
}

void calc (int x) {
    int i, j;
    up.clear();
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (vis[j]) continue;
        dfs(j, x, 1, edge[i].w, 1);
    }
    ans += up[0]; ++up[0];
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (vis[j]) continue;
        dfs(j, x, 1, edge[i].w, -1);
        dfs2(j, x, edge[i].w, 1);
        dfs(j, x, 1, edge[i].w, 1);
        //printf("%d %d\n", j, ans);
    }
}

void solve (int x) {
    int i, j;
    vis[x] = true; calc(x);
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (vis[j]) continue;
        root = 0, sall = siz[j]; getroot(j, 0);
        solve(root);
    }
}

int main () {
    n = read(), M = read();
    int i, j;
    for (i = 1; i < n; i++) {
        int u = read() + 1, v = read() + 1, w = read() % M;
        add(u, v, w), add(v, u, w);
    }
    root = 0, sall = n; getroot(1, 0); //cout << root << endl;
    solve(root);
    printf("%lld\n", ans);
    return 0;
}