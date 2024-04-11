#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

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

const int MAXN = 200200; const ll inf = 1e16;
vector <int> E[MAXN];
int fa[MAXN], dep[MAXN], n, a[MAXN];
vector <int> tmp; bool cmp (int x, int y) { return dep[x] > dep[y]; }
void pre (int x, int f) { dep[x] = dep[f] + 1; for (auto i: E[x]) pre(i, x); }

ll mx[MAXN], mn[MAXN], pos[MAXN], neg[MAXN], F[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 2; i <= n; i++) {
            fa[i] = read();
            E[fa[i]].push_back(i);
        }
        for (i = 2; i <= n; i++) a[i] = read();
        pre(1, 0); tmp.clear();
        for (i = 1; i <= n; i++) tmp.push_back(i);
        sort(tmp.begin(), tmp.end(), cmp);
        for (i = 1; i <= n; i++) mx[i] = pos[i] = neg[i] = -inf, mn[i] = inf;
        for (auto x: tmp) {
            int d = dep[x]; F[x] = 0;
            ll _mx = -inf, _mn = inf;
            for (auto v: E[x]) {
                F[x] = max(F[x], F[v] + max(a[v] - mn[d + 1], mx[d + 1] - a[v]));
                _mx = max(_mx, (ll)a[v]); _mn = min(_mn, (ll)a[v]);
            }
            F[x] = max(F[x], max(neg[d + 1] + _mx, pos[d + 1] - _mn));
            mx[d] = max(mx[d], (ll)a[x]); mn[d] = min(mn[d], (ll)a[x]);
            pos[d] = max(pos[d], F[x] + a[x]); neg[d] = max(neg[d], F[x] - a[x]);
        }
        printf("%lld\n", F[1]);
        for (i = 1; i <= n; i++) E[i].clear(), fa[i] = dep[i] = F[i] = 0;
    }
    return 0;
}