#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ll long long
const int MAXN = 200200;
int p[MAXN], mu[MAXN], top; bool np[MAXN];
void pre () {
    mu[1] = 1; int i, j;
    for (i = 2; i <= 200000; i++) {
        if (!np[i]) p[++top] = i, mu[i] = -1;
        for (j = 1; j <= top && i * p[j] <= 200000; j++) {
            np[i * p[j]] = 1;
            if (i % p[j] == 0) { mu[i * p[j]] = 0; break; }
            mu[i * p[j]] = -mu[i];
        }
    }
}

int n, a[MAXN]; vector <int> E[MAXN], s[MAXN];
int cur; ll f[MAXN];

bool vis[MAXN];
int dfs (int x) {
    int ret = 1; vis[x] = 1;
    for (auto i: E[x]) if (!vis[i] && a[i] % cur == 0) ret += dfs(i);
    return ret;
}

int main () {
    pre();
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    for (i = 1; i <= n; i++) {
        int x = a[i];
        for (j = 1; j * j <= x; j++) if (x % j == 0) {
            s[j].push_back(i);
            if (j * j != x) s[x / j].push_back(i);
        }
    }
    for (cur = 1; cur <= 200000; cur++) {
        for (auto i: s[cur]) if (!vis[i]) {
            j = dfs(i);
            f[cur] += 1ll * j * (j + 1) / 2;
        }	
        for (auto i: s[cur]) vis[i] = 0;
    }
    for (i = 1; i <= 200000; i++) {
        ll ans = 0;
        for (j = i; j <= 200000; j += i) ans += f[j] * mu[j / i];
        if (ans) printf("%d %lld\n", i, ans);
    }
    return 0;
}