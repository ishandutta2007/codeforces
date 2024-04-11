#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    long long p = n * 1ll * m, q = k;
    long long g = __gcd(p, q);
    p /= g, q /= g;
    if (q > 2) {
        puts("NO");
        return 0;
    }
    if (n * 1ll * m * q < 2 * p) {
        puts("NO");
        return 0;
    }
    if (q == 1) p *= 2;
    for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
        if (p % i == 0) {
            if (p / i <= m) {
                puts("YES");
                printf("%d %d\n", 0, 0);
                printf("%d %d\n", i, 0);
                printf("%d %d\n", 0, (int)(p / i));
                return 0;
            }
        }
        if (p % (n / i) == 0) {
            if (p / (n / i) <= m) {
                puts("YES");
                printf("%d %d\n", 0, 0);
                printf("%d %d\n", n / i, 0);
                printf("%d %d\n", 0, (int)(p / (n / i)));
                return 0;
            }
        }
    }
    for (int i = 1; i * i <= m; ++i) if (m % i == 0) {
        if (p % i == 0) {
            if (p / i <= n) {
                puts("YES");
                printf("%d %d\n", 0, 0);
                printf("%d %d\n", 0, i);
                printf("%d %d\n", (int)(p / i), 0);
                return 0;
            }
        }
        if (p % (m / i) == 0) {
            if (p / (m / i) <= n) {
                puts("YES");
                printf("%d %d\n", 0, 0);
                printf("%d %d\n", 0, m / i);
                printf("%d %d\n", (int)(p / (m / i)), 0);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}