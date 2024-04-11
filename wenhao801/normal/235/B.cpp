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

const int MAXN = 100100;

int n;
double p[MAXN];
double x1[MAXN], x2[MAXN], ans[MAXN];

int main () {
    n = read();
    int i, j;
    for (i = 1; i <= n; i++) scanf("%lf", &p[i]);
    for (i = 1; i <= n; i++)
        x1[i] = (x1[i - 1] + 1) * p[i],
        ans[i] = ans[i - 1] + (2 * x1[i - 1] + 1) * p[i];
    printf("%.9lf\n", ans[n]);
    return 0;
}