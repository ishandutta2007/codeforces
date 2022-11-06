#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long a, m; scanf("%lld%lld", &a, &m);
        long long g = __gcd(a, m), k = m / g;
        long long phi = 1;
        for (long long p = 2; p * p <= k; ++p) {
            if (k % p == 0) {
                long long mult = 1;
                while (k % p == 0) {
                    k /= p;
                    mult *= p;
                }
                phi *= mult / p * (p - 1);
            }
        }
        if (k > 1) phi *= k - 1;
        printf("%lld\n", phi);
    }
    return 0;
}