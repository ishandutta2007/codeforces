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

const int mod = 998244353, MAXN = 1000010, lim = 1e6;
int p[MAXN], mu[MAXN], fir[MAXN], top; bool np[MAXN];
void sieve () {
    int i, j; mu[1] = 1;
    for (i = 2; i <= lim; i++) {
        if (!np[i]) p[++top] = i, mu[i] = -1, fir[i] = i;
        for (j = 1; j <= top; j++) {
            if (p[j] * i > lim) break;
            np[p[j] * i] = 1; fir[p[j] * i] = p[j];
            if (i % p[j] == 0) { mu[i * p[j]] = 0; break; }
            mu[i * p[j]] = -mu[i];
        }
    }
}

int n, f[MAXN]; vector <int> E[MAXN];
bool vis[MAXN]; int now[MAXN];

void clear () {
    for (int i = 0; i <= n; i++) f[i] = 0, vis[i] = 0, E[i].clear();
}

int cp;
bool pre (int x, int fa) {
	bool leaf = 1, sonleaf = 1;
	for (auto i: E[x]) if (i != fa) leaf = 0, sonleaf &= pre(i, x);
	if (!leaf && sonleaf) cp = x;
	return leaf;
}
bool dfs (int x, int fa, int pr) {
    for (auto i: E[x]) if (i != fa) {
        if (!dfs(i, x, pr)) return 0;
    }
    if (now[x] % pr != 0 && (now[x] % pr != pr - 1 || !fa)) return 0;
    if (now[x] % pr == 0) ++now[fa]; else ++now[x];
    return 1;
}
inline int gcd (int x, int y) { return !y ? x : gcd(y, x % y); }
void calc (int pr) {
    int i, j; vis[pr] = 1;
    for (i = 0; i <= n; i++) now[i] = 0;
    if (dfs(1, 0, pr)) {
        int tmp = 0;
        for (i = 1; i <= n; i++) tmp = gcd(tmp, now[i]);
        for (i = 1; i * i <= tmp; i++) if (tmp % i == 0) vis[i] = vis[tmp / i] = 1, f[i] = f[tmp / i] = 1;
    }
}
void out (int x) {
    if (x >= 10) out(x / 10);
    putchar(x % 10 + '0');
}

int main () {
    sieve();
    int T = read();
    while (T--) {
        n = read(); int i, j;
        f[1] = 1;
        for (i = 1; i < n; i++) {
            int u = read(), v = read();
            E[u].push_back(v), E[v].push_back(u);
        }
        if (n == 1) { puts("1"); clear(); continue; }
        if (n == 2) { puts("2 0"); clear(); continue; }
        pre(1, 0);
		int deg = E[cp].size();
        for (j = 1; p[j] <= deg && j <= top; j++) if (!vis[p[j]] && (deg % p[j] == 0 || (deg - 1) % p[j] == 0)) calc(p[j]);
        f[1] = 1; for (i = 1; i < n; i++) f[1] = (f[1] << 1) % mod;
        for (i = 1; i <= n; i++) for (j = 2; j * i <= n; j++) f[i] = (f[i] + mu[j] * f[i * j]) % mod;
        for (i = 1; i <= n; i++) out((f[i] + mod) % mod), putchar(' ');
        putchar('\n');
        clear();
    }
    return 0;
}