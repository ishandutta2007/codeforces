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

const int MAXN = 1010;
int n, a[MAXN];
bool cmp (int x, int y) { return x > y; }

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        a[i] = read(); a[i] += read();a[i] += read();a[i] += read();
    }
    for (j = 1, i = 2; i <= n; i++) {
        if (a[1] < a[i]) ++j;
    }
    cout << j;
    return 0;
}