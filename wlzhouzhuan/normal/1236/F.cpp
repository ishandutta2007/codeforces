#include <bits/stdc++.h>
using namespace std;
 
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define pb push_back
#define ll long long
// !
#define int long long
 
int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
 
/*
V: 
E: 
C: 
*/
 
const int N = 500005;
const ll P = 1e9 + 7;
ll qpow(ll a, ll b = P - 2) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}
const int i2 = qpow(2);
const int i3 = qpow(3);
const int i4 = qpow(4);
const int i5 = qpow(5);
const int i6 = qpow(6);
 
vector<int> vec[N], adj[N];
void add(int u, int v) { adj[u].push_back(v); }
 
int dep[N], fa[N], inv2[N];
int n, m, rd[N], u, v, tot;
int siz[N], sum[N], sum2[N], sd[N];
bool vis[N];
 
ll circ = 0;
void dfs(int x) {
    vis[x] = 1;
    for (auto j : adj[x]) {
        if (j == fa[x])
            continue;
        int k;
        if (vis[j]) {
            if (dep[x] > dep[j]) {
                ++tot;
                for (k = x; k ^ j; k = fa[k]) vec[tot].push_back(k);
                vec[tot].push_back(j), siz[tot] = vec[tot].size();
                circ = (circ + inv2[siz[tot]]) % P;
            }
            continue;
        }
        fa[j] = x;
        dep[j] = dep[x] + 1;
        dfs(j);
    }
}
int sqr(int x) { return 1ll * x * x % P; }
int E() {
    int ans = 0;
    for (int i = 1; i <= tot; ++i) ans = (ans + inv2[siz[i]]) % P;
    return (ans + 1ll * n * inv2[1] % P - 1ll * m * inv2[2] % P) % P;
}
int vv() { return (sqr(n) + n + 0ll) * inv2[2] % P; }
int cc() {
    int ans = 0, i;
    for (i = 1; i <= tot; ++i) ans = (ans + inv2[siz[i]]) % P;
    ans = (ans + 1ll * ans * ans % P) % P;
    for (i = 1; i <= tot; ++i) ans = (ans - inv2[siz[i] << 1]) % P;
    for (i = 1; i <= n; ++i) ans = (ans + sqr(sum[i]) - sum2[i]) % P;
    return ans;
}
int ee() {
    int ans = (sqr(m) + m) % P;
    for (int i = 1; i <= n; ++i) ans = (ans + sqr(rd[i])) % P;
    return 1ll * ans * inv2[4] % P;
}
int vc() {
    int ans = 0;
    for (int i = 1; i <= tot; ++i) ans = (ans + 1ll * (siz[i] + n) * inv2[siz[i] + 1] % P) % P;
    return ans;
}
int ve() { return (2ll + n) * m % P * inv2[3] % P; }
int ce() {
    int ans = 0;
    for (register int i = 1; i <= tot; ++i)
        ans =
            (ans + 1ll * inv2[siz[i]] *
                       (siz[i] + 1ll * sd[i] * inv2[1] % P + 1ll * (m - siz[i] - sd[i]) * inv2[2] % P) % P) %
            P;
    return ans;
}
 
signed main() {
    n = read(), m = read();
    inv2[0] = 1, inv2[1] = qpow(2);
    for (int i = 2; i < N; i++) inv2[i] = 1ll * inv2[i - 1] * inv2[1] % P;
    int i, j, x;
    for (i = 1; i <= m; ++i) {
        int u = read(), v = read();
        ++rd[u], ++rd[v];
        add(u, v), add(v, u);
    }
    dfs(1);
    for (i = 1; i <= tot; ++i) {
        for (j = 0; j < siz[i]; ++j)
            x = vec[i][j], sd[i] += rd[x], sum[x] = (sum[x] + inv2[siz[i]]) % P,
            sum2[x] = (sum2[x] + sqr(inv2[siz[i]])) % P;
        sd[i] -= (siz[i] << 1);
    }
    /*
    printf("%lld\n", (1ll * n * i2 % P + P) % P);
    printf("%lld\n", (1ll * m * i4 % P + P) % P);
    printf("%lld\n", (circ % P + P) % P);
    printf("%lld\n", ((1ll * n * i2 - 1ll * m * i4 + circ) % P + P) % P);
    printf("%lld\n", (vv() % P + P) % P);
    printf("%lld\n", (ee() % P + P) % P);
    printf("%lld\n", (cc() % P + P) % P);
    printf("%lld\n", (ve() % P + P) % P);
    printf("%lld\n", (vc() % P + P) % P);
    printf("%lld\n", (ce() % P + P) % P);
    printf("%lld\n", ((vv() + cc() + ee() + (vc() - ve() - ce()) * 2ll % P) % P + P) % P);
    */
    printf("%lld\n", (((vv() + cc() + ee() + (vc() - ve() - ce()) * 2ll % P - sqr(E())) % P + P) % P + P) % P);
    return 0;
}