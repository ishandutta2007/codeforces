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

int n;
int a[1010] = {};

int main () {
    int T = read();
    while (T--) {
        int i, j;
        n = read();
        int Max = 1;
        for (i = 1; i <= n; i++) a[i] = read();
        sort(a + 1, a + n + 1);
        for (i = n; i >= 1; i--) if (a[i] > Max && (n - i + 1) > Max) Max = min(a[i], n - i + 1);
        printf("%d\n", Max);
    }
    return 0;
}