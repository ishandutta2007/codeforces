#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

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

int T;
int gcd (int x, int y ) { if (!y) return x; return gcd(y, x % y); }

int getphi (int x) {
    int rua = (int)(sqrt(x));
    int ans = x;
    int i, j;
    for (i = 2; i <= rua; i++) {
        if (x % i == 0) {
            ans = ans / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans = ans / x * (x - 1);
    return ans;
}

signed main () {
    T = read();
    while (T--) {
        int a = read(), m = read();
        int rua = gcd(a, m);
        a /= rua, m /= rua;
        printf("%lld\n", getphi(m));
    }
    return 0;
}