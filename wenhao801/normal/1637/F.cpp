#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
using pii = pair <int, ll>;
const int MAXN = 200200;
vector <int> E[MAXN];

int n, a[MAXN];
pii dfs(int x, int f) {
    ll ret = 0; int mx = 0, mx2 = 0;
    for (auto i: E[x]) if (i != f) {
        pii tmp = dfs(i, x);
        ret += tmp.second;
        if (tmp.first > mx) mx2 = mx, mx = tmp.first;
        else if (tmp.first > mx2) mx2 = tmp.first;
    }
    if (mx < a[x]) ret += a[x] - mx, mx = a[x];
    if (!f) ret += mx - mx2;
    return {mx, ret};
}

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    if (n == 2) { printf("%d\n", max(a[1], a[2]) * 2); return 0; }
    int rt = max_element(a + 1, a + n + 1) - a;
    printf("%lld\n", dfs(rt, 0).second);
    return 0;
}