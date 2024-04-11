#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 300300;
int st[MAXN][22] = {};
int n;

int qry (int l, int r) {
    int len = log2(r - l + 1);
    return __gcd(st[l][len], st[r - (1 << len) + 1][len]);
}

int ans[MAXN], top;

int main () {
    n = read();
    int i, j;
    int maxlen = 0;
    for (i = 1; i <= n; i++) st[i][0] = read();
    for (i = 1; i <= 20; i++) for (j = 1; j <= n; j++) if (j + (1 << (i - 1)) <= n) st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    for (i = 1; i <= n; i++) {
        int l = 1, r = i;
        int L, R;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (qry(mid, i) % st[i][0]) l = mid + 1;
            else r = mid - 1, L = mid;
        }
        l = i, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (qry(i, mid) % st[i][0]) r = mid - 1;
            else l = mid + 1, R = mid;
        }
        if (R - L > maxlen) maxlen = R - L, top = 0, ans[++top] = L;
        else if (R - L == maxlen) ans[++top] = L;
    }
    sort(ans + 1, ans + top + 1);
    top = unique(ans + 1, ans + top + 1) - ans - 1;
    printf("%d %d\n", top, maxlen);
    for (i = 1; i <= top; i++) printf("%d ", ans[i]);
    return 0;
}