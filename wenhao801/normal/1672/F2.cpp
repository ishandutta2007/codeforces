#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

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

const int MAXN = 200200;
int n, a[MAXN], b[MAXN];
pii buc[MAXN];
vector <int> E[MAXN]; int ind[MAXN]; queue <int> q;

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j, cost = n;
        for (i = 1; i <= n; i++) a[i] = read(), ++buc[a[i]].fr, buc[i].se = i;
        sort(buc + 1, buc + n + 1, [](pii u, pii v) { return u.fr > v.fr; });
        for (i = 1; i <= n; i++) {
            b[i] = read();
            if (a[i] != buc[1].se && b[i] != buc[1].se) E[a[i]].emplace_back(b[i]), ++ind[b[i]];
        }
        for (i = 2; i <= n; i++) if (!ind[buc[i].se]) q.push(buc[i].se);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto i: E[x]) {
                --ind[i];
                if (!ind[i]) q.push(i);
            }
        }
        for (i = 1; i <= n; i++) if (ind[i]) { puts("WA"); break; }
        if (i > n) puts("AC");
        for (i = 1; i <= n; i++) buc[i] = {0, 0}, ind[i] = 0, E[i].clear();
    }
    return 0;
}