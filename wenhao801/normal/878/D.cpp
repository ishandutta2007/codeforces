#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 100100;

bool cmp (pii x, pii y) { return x.fr < y.fr; }
int n, K, q, a[13][MAXN];
bitset <4096> f[MAXN];

int main () {
    n = read(), K = read(), q = read(); int i, j, top = K;
    for (i = 1; i <= K; i++) {
        for (j = 1; j <= n; j++) a[i][j] = read();
        for (j = 0; j < (1 << K); j++) f[i][j] = (j >> (i - 1)) & 1;
    }
    for (i = 1; i <= q; i++) {
        int op = read(), x = read(), y = read();
        if (op == 1) f[++top] = f[x] | f[y];
        if (op == 2) f[++top] = f[x] & f[y];
        if (op == 3) {
            int cur = 0; pii tmp[13];
            for (j = 1; j <= K; j++) tmp[j] = make_pair(a[j][y], j);
            sort(tmp + 1, tmp + K + 1, cmp);
            for (j = K; j >= 1; j--) {
                cur += 1 << (tmp[j].se - 1);
                if (f[x][cur]) { printf("%d\n", tmp[j].fr); break; }
            }
        }
    }
    return 0;
}