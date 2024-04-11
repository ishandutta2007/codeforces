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

#define ll long long
const int MAXN = 400400;
#define pii pair<int, int>
#define fr first
#define se second

int n; pii a[MAXN];
vector <pii> E[MAXN];

namespace init {
    pair <ll, ll> b[MAXN], u[MAXN], v[MAXN]; int top;
    int Hash (pair <ll, ll> x) { return lower_bound(b + 1, b + top + 1, x) - b; }
    void main () {
        int i, j;
        for (i = 1; i <= n; i++) {
            ll x = read(), y = read(), z = read(), w = read(), tmp;
            u[i] = make_pair(z * y, (x + y) * w); v[i] = make_pair(y * (z + w), x * w);
            if (!u[i].fr) u[i].se = 1; else if (!u[i].se) u[i].fr = 1; else tmp = __gcd(u[i].fr, u[i].se), u[i].fr /= tmp, u[i].se /= tmp;
            if (!v[i].fr) v[i].se = 1; else if (!v[i].se) v[i].fr = 1; else tmp = __gcd(v[i].fr, v[i].se), v[i].fr /= tmp, v[i].se /= tmp;
            b[++top] = u[i]; b[++top] = v[i];
        }
        sort(b + 1, b + top + 1); top = unique(b + 1, b + top + 1) - b - 1;
        for (i = 1; i <= n; i++) a[i].fr = Hash(u[i]), a[i].se = Hash(v[i]); //, printf("(%d %d)\n", a[i].fr, a[i].se);
    }
}

bool vis[MAXN]; int dep[MAXN]; vector <pii> ans;
int dfs (int x, int fa) {
    vis[x] = 1; int wait_son = 0, wait_back = 0;
    for (auto v: E[x]) if (v.se != fa) {
        if (vis[v.fr] && dep[v.fr] < dep[x]) {
            if (!wait_back) wait_back = v.se;
            else ans.push_back(make_pair(wait_back, v.se)), wait_back = 0;
        }
        else if (!vis[v.fr]) {
            dep[v.fr] = dep[x] + 1; int res = dfs(v.fr, v.se);
            if (!res) {
                if (!wait_son) wait_son = v.se;
                else ans.push_back(make_pair(wait_son, v.se)), wait_son = 0;
            }
            else ans.push_back(make_pair(res, v.se));
        }
        // printf("x = %d, v = %d, wait_son = %d\n", x, v, wait_son);
    }
    if (wait_son && wait_back) { ans.push_back(make_pair(wait_son, wait_back)); return 0; }
    return wait_son | wait_back;
}

int main () {
    n = read(); init::main();
    int i, j;
    for (i = 1; i <= n; i++)
        E[a[i].fr].push_back(make_pair(a[i].se, i)), E[a[i].se].push_back(make_pair(a[i].fr, i));
    for (i = 1; i <= (n << 1); i++) if (!vis[i]) dfs(i, 0); //, printf("%d, ans = %d\n", i, ans.size());
    printf("%d\n", ans.size());
    for (auto v: ans) printf("%d %d\n", v.fr, v.se);
    return 0;
}