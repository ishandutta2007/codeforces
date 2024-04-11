#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n; char a[(1 << 18) + 5];
int rk[1 << 18], sa[1 << 18], cur, tmp[1 << 18];
int cmp (int u, int v) {
    if (rk[u] != rk[v]) return rk[u] < rk[v] ? 1 : -1;
    u ^= 1 << cur, v ^= 1 << cur;
    if (rk[u] != rk[v]) return rk[u] < rk[v] ? 1 : -1;
    return 0;
}
bool _cmp (int u, int v) { return cmp(u, v) == 1; }

int main () {
    n = read(); int i, j;
    scanf("%s", a);
    for (i = 0; i < (1 << n); i++) rk[i] = a[i] - 'a', sa[i] = i;
    for (cur = 0; cur < n; cur++) {
        sort(sa, sa + (1 << n), _cmp);
        tmp[sa[0]] = 0;
        for (i = 1; i < (1 << n); i++) if (cmp(sa[i - 1], sa[i]) == 0) tmp[sa[i]] = tmp[sa[i - 1]]; else tmp[sa[i]] = i;
        for (i = 0; i < (1 << n); i++) rk[i] = tmp[i];
    }
    for (i = 0; i < (1 << n); i++) putchar(a[i ^ sa[0]]);
    putchar('\n');
    return 0;
}