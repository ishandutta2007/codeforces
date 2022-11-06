#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7;
int v[maxn], sz[2][maxn], ans, n;
vector<int> graf[maxn];

void dfs1(int now, int fa) {
    sz[0][now] = 1;
    for (int u : graf[now]) if (u != fa) {
        dfs1(u, now);
        for (int z = 0; z < 2; ++z) sz[z][now] += sz[z ^ 1][u];
        int usz = sz[0][u] + sz[1][u];
        ans += v[now] * 1ll * sz[1][u] % mod * 1ll * (n - usz) % mod;
        ans %= mod;
        ans += (mod - v[now]) * 1ll * sz[0][u] % mod * 1ll * (n - usz) % mod;
        ans %= mod;
    }
    ans += v[now] * 1ll * (n - sz[0][now] - sz[1][now]) % mod;
    ans %= mod;
}

void dfs2(int now, int fa, vector<int> p) {
    int nsz = sz[0][now] + sz[1][now];
    ans += v[now] * 1ll * p[0] % mod * 1ll * nsz % mod;
    ans %= mod;
    ans += (mod - v[now]) * 1ll * p[1] % mod * 1ll * nsz % mod;
    ans %= mod;
    ans += v[now] * 1ll * (nsz - 1) % mod;
    ans %= mod;
    vector<int> f = { p[1], p[0] };
    ++f[1];
    for (int u : graf[now]) if (u != fa) {
        for (int z = 0; z < 2; ++z) f[z] += sz[z][u];
    } 
    for (int u : graf[now]) if (u != fa) {
        for (int z = 0; z < 2; ++z) f[z] -= sz[z][u];
        dfs2(u, now, f);
        for (int z = 0; z < 2; ++z) f[z] += sz[z][u];
    }
}

int main() { 
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", v + i), (v[i] += mod) %= mod;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b); --a, --b;
        graf[a].push_back(b), graf[b].push_back(a);
    }
    dfs1(0, -1); 
    for (int i = 0; i < n; ++i) (ans += v[i]) %= mod;
    dfs2(0, -1, { 0, 0 });
    printf("%d\n", ans);
    return 0;
}