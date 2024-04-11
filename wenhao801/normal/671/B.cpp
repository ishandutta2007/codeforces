#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 500500;
int n, K, a[MAXN];

int main () {
    n = read(), K = read(); int i, j;
    ll sum = 0;
    for (i = 1; i <= n; i++) a[i] = read(), sum += a[i];
    sort(a + 1, a + n + 1);
    ll resL = a[1], resR = a[n];
    for (i = 2, j = K; i <= n; i++) {
        ll d = a[i] - a[i - 1];
        if (j < d * (i - 1)) {
            resL += j / (i - 1);
            break;
        }
        resL += d; j -= d * (i - 1);
    }
    for (i = n - 1, j = K; i >= 1; i--) {
        ll d = a[i + 1] - a[i];
        if (j < d * (n - i)) {
            resR -= j / (n - i);
            break;
        }
        resR -= d; j -= d * (n - i);
    }
    if (resL >= resR) putchar('0' + bool(sum % n)), putchar('\n'); else printf("%lld\n", resR - resL);
    return 0;
}