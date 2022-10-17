#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

using LL = __int128;
inline LL read() {
    LL ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, m; LL p[100100]; int id[100100];
int main() {
    int T = read(); while (T--) {
        n = read(), m = read(); int i, j;
        for (i = 1; i <= n; i++) {
            p[i] = 0; id[i] = i;
            for (j = 1; j <= m; j++) p[i] += LL(j) * read();
        }
        sort(id + 1, id + n + 1, [](int u, int v) { return p[u] < p[v]; });
        printf("%d %lld\n", id[n], (long long)(p[id[n]] - p[id[1]]));
    }
    return 0;
}