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

int main () {
    long long n = read(), m = read(), k = read();
    if (2ll * n * m % k != 0 || k == 1) puts("NO");
    else {
        puts("YES");
        long long now = 2ll * n * m / k;
        if (now % n == 0) { printf("0 0\n%lld 0\n0 %lld\n", n, now / n); }
        else if (now % m == 0) { printf("0 0\n0 %lld\n%lld 0\n", m, now / m); }
        else {
            for (long long i = 1; i * i <= now; i++) if (now % i == 0) {
                if (i <= n && now / i <= m) {
                    printf("0 0\n%lld 0\n0 %lld\n", i, now / i);
                    return 0;
                }
                if (i <= m && now / i <= n) {
                    printf("0 0\n%lld 0\n0 %lld\n", now / i, i);
                    return 0;
                }
                
            }
        }
    }
    return 0;
}