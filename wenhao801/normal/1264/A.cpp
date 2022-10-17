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
 
int n, m;
int a[400400] = {};
int b[400400] = {};
 
int P[5] = {};
 
bool check (int x) {
    P[1] = b[1], P[2] = 0, P[3] = 0;
    int i, j;
    for (i = 2; i <= m; i++) {
        P[2] += b[i];
        if (P[2] > P[1]) break;
    }
    if (x <= P[1] + P[2]) return false;
    for (j = i + 1; j <= m; j++) {
        P[3] += b[j];
        if (P[1] + P[2] + P[3] >= x) break;
    }
    if (P[1] + P[2] + P[3] > x) P[3] -= b[j];
    if (P[1] + P[2] + P[3] <= x && P[1] < P[2] && P[1] < P[3]) return true;
    return false;
}
 
int main () {
    int T = read();
    while (T-- ){
        n = read();
        int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), b[i] = 0;
        if (n < 10) { puts("0 0 0"); continue; }
        m = 0;
        for (i = 1; i <= n; i++) if (a[i] != a[i - 1]) b[++m]++; else b[m]++;
        if (check(n / 2))
            printf("%d %d %d\n", P[1], P[2], P[3]);
        else puts("0 0 0");
    }
    return 0;
}