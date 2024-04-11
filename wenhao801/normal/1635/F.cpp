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

const int MAXN = 300300;
int n, q, pos[MAXN], w[MAXN];
int f[MAXN][22], lg2[MAXN];

bool cmp (int u, int v) { if (w[u] == w[v]) return u < v; return w[u] < w[v]; }

int ch[MAXN][2];
vector <int> a[MAXN], b[MAXN];
void solve (int l, int r, int &fa) {
    if (l > r) return;
    int len = lg2[r - l + 1], rt = cmp(f[l][len], f[r - (1 << len) + 1][len]) ? f[l][len] : f[r - (1 << len) + 1][len];
    fa = rt;
    solve(l, rt - 1, ch[rt][0]), solve(rt + 1, r, ch[rt][1]);
}

#define ll long long
const ll inf = 4e18;

ll t[MAXN];
inline int lowbit (int x) { return x & -x; }
inline void add (int x, ll k) { while (x <= n) t[x] = min(t[x], k), x += lowbit(x); }
inline ll query (int x) { ll ret = inf; while (x) ret = min(ret, t[x]), x -= lowbit(x); return ret; }

int L[MAXN], R[MAXN]; ll ans[MAXN];

int main () {
    n = read(), q = read(); int i, j;
    for (i = 1; i <= n; i++) pos[i] = read(), w[i] = read(), f[i][0] = i;
    for (i = 1; i <= 20; i++) for (j = 1; j + (1 << i) - 1 <= n; j++)
        f[j][i] = cmp(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]) ? f[j][i - 1] : f[j + (1 << (i - 1))][i - 1];
    lg2[0] = -1; for (i = 1; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    solve(1, n, ch[0][0]);
    for (i = 1; i <= n; i++) {
        int x = ch[i][1];
        while (x) {
            a[i].push_back(x);
            x = ch[x][0];
        }
        x = ch[i][0];
        while (x) {
            a[x].push_back(i);
            x = ch[x][1];
        }
        t[i] = inf;
    }
    for (i = 1; i <= q; i++) L[i] = read(), R[i] = read(), b[L[i]].push_back(i);
    for (i = n; i >= 1; i--) {
        for (auto j: a[i]) add(j, 1ll * abs(pos[i] - pos[j]) * (w[i] + w[j]));
        for (auto j: b[i]) ans[j] = query(R[j]);
    }
    for (i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0;
}