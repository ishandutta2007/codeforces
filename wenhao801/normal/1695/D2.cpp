#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
int n, d[MAXN], a[MAXN];
vector <int> E[MAXN];

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        if (n == 1) { puts("0"); continue; }
        for (i = 1; i < n; i++) {
            int u = read(), v = read();
            E[u].push_back(v), E[v].push_back(u);
            ++d[u], ++d[v];
        }
        if (*max_element(d + 1, d + n + 1) <= 2) puts("1"); else {
            int ans = 0;
            for (i = 1; i <= n; i++) if (d[i] == 1) {
                int now = E[i][0], las = i;
                while (d[now] == 2) swap(now, las), now = E[las][0] ^ E[las][1] ^ now;
                if (a[now]) ++ans; else a[now] = 1;
            }
            printf("%d\n", ans);
        }
        for (i = 1; i <= n; i++) E[i].clear(), d[i] = a[i] = 0;
    }
    return 0;
}