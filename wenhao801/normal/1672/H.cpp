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

const int MAXN = 200200;
int n, m, a[MAXN][2]; char s[MAXN];

int main () {
    n = read(), m = read(); int i, j;
    scanf("%s", s + 1);
    for (i = 2; i <= n; i++) a[i][0] = a[i - 1][0] + (s[i] == '0' && s[i - 1] == '0'), a[i][1] = a[i - 1][1] + (s[i] == '1' && s[i - 1] == '1');
    while (m--) {
        int l = read(), r = read();
        printf("%d\n", max(a[r][0] - a[l][0], a[r][1] - a[l][1]) + 1);
    }
    return 0;
}