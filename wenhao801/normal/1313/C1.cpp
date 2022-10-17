#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define int long long

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
int a[100100];
int b[100100];
signed main () {
    int n = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    int ans = 0, pos = 0;
    for (i = 1; i <= n; i++) {
        int s = a[i]; int Min = a[i];
        for (j = i - 1; j >= 1; j--) {
            Min = min(Min, a[j]);
            s += Min;
        } Min = a[i];
        for (j = i + 1; j <= n; j++) {
            Min = min(Min, a[j]);
            s += Min;
        }
        if (ans < s) ans = s, pos = i;
    }
    int Min = a[pos]; b[pos] = a[pos];
    for (i = pos - 1; i >= 1; i--) Min = min(Min, a[i]), b[i] = Min; Min = a[pos];
    for (i = pos + 1; i <= n; i++) Min = min(Min, a[i]), b[i] = Min;
    for (i = 1; i <= n; i++) printf("%lld ", b[i]);

    return 0;
}