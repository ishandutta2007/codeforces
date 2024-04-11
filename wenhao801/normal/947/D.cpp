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
int a[MAXN], b[MAXN], lass[MAXN], last[MAXN]; char s[MAXN], t[MAXN];

int main () {
    int i, j, n, m;
    scanf("%s%s", s + 1, t + 1); n = strlen(s + 1), m = strlen(t + 1);
    for (i = 1; i <= n; i++) lass[i] = (s[i] == 'A') ? lass[i - 1] : i;
    for (i = 1; i <= m; i++) last[i] = (t[i] == 'A') ? last[i - 1] : i;
    for (i = 1; i <= n; i++) a[i] = a[i - 1] + (s[i] != 'A');
    for (i = 1; i <= m; i++) b[i] = b[i - 1] + (t[i] != 'A');
    int q = read(); while (q--) {
        int l1 = read(), r1 = read(), l2 = read(), r2 = read();
        int ta = max(l1 - 1, lass[r1]), tb = max(l2 - 1, last[r2]), ca = a[r1] - a[l1 - 1], cb = b[r2] - b[l2 - 1];
        if (r1 - ta < r2 - tb) { putchar('0'); continue; }
        
        if (r1 - ta == r2 - tb) {
            if (ta == l1 - 1 && tb == l2 - 1) putchar('1');
            else if (ta != l1 - 1 && ca <= cb && (cb - ca) % 2 == 0) putchar('1'); else putchar('0');
        }
        else {
            if ((r1 - ta - (r2 - tb)) % 3 == 0) ca -= 2;
            ca += 2;
            if (ca <= cb && (cb - ca) % 2 == 0) putchar('1'); else putchar('0');
        }
    }
    return 0;
}