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

#define ll long long
const int MAXN = 100100;
int n; ll a[MAXN], t[MAXN], st[MAXN], ans[MAXN], out[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= n; i++) t[i] = read(), st[i] = st[i - 1] + t[i];
    for (i = 1; i <= n; i++) {
        int L = i, R = n, res = i - 1;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (st[mid] - st[i - 1] >= a[i]) R = mid - 1;
            else L = mid + 1, res = mid;
        }
        ++ans[i], --ans[res + 1];
        a[i] -= st[res] - st[i - 1];
        out[res + 1] += a[i];
    }
    for (i = 1; i <= n; i++) ans[i] += ans[i - 1], printf("%lld ", out[i] + ans[i] * t[i]);
    return 0;
}