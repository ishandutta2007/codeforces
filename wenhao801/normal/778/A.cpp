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
char s[MAXN], t[MAXN]; int n, m, a[MAXN];

bool check (int lim) {
    int now = 1, i;
    for (i = 1; i <= n; i++) if (a[i] >= lim) {
        if (s[i] == t[now]) ++now;
        if (now > m) return 1;
    }
    return 0;
}

int main () {
    scanf("%s", s + 1); n = strlen(s + 1);
    scanf("%s", t +1); m = strlen(t + 1);
    int i, j;
    for (i = 1; i <= n; i++) a[read()] = i;
    int L = 1, R = n, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (check(mid)) L = mid + 1, ans = mid;
        else R = mid - 1;
    }
    printf("%d\n", ans - 1);
    return 0;
}