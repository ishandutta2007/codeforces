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

#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 3030;
vector <pii> E[MAXN]; int n;

int ans = 1e9 + 7, tmp;

int dfs (int x, int fa, int cur) {
    int ret = cur;
    for (auto i: E[x]) if (i.fr != fa) {
        tmp += i.se;
        ret = min(ret, dfs(i.fr, x, cur + (i.se ? -1 : 1)));
    }
    return ret;
}

int main () {
    n = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(make_pair(v, 0));
        E[v].push_back(make_pair(u, 1));
    }
    for (i = 1; i <= n; i++) {
        tmp = 0; int mn1 = 1e9 + 7, mn2 = 1e9 + 7;
        for (auto j: E[i]) {
            tmp += j.se; int res = dfs(j.fr, i, (j.se ? -1 : 1));
            if (res <= mn1) mn2 = mn1, mn1 = res;
            else if (res <= mn2) mn2 = res;
        }
        ans = min(ans, tmp);
        ans = min(ans, mn1 + mn2 + tmp);
    }
    printf("%d\n", ans);
    return 0;
}