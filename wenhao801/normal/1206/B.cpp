#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n;
int a[101000] = {};
bool f = false;

signed main () {
    n = read();
    int i, j;
    for (i = 1; i <= n; i++)
        a[i] = read();
    int ans = 0;
    int cnt = 0;
    for (i = 1; i <= n; i++) {
        if (a[i] == 0) f = true, ans++;
        if (a[i] > 0) {
            ans += a[i] - 1;
        }
        if (a[i] < 0) {
            ans += -1 - a[i];
            cnt++;
        }
    }
    if (cnt % 2 && !f) ans += 2;
    printf("%lld\n", ans);
    return 0;
}