#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k; scanf("%lld %lld %lld", &n, &m, &k);
    if (k < n) {
        printf("%lld 1\n", k + 1);
        return 0;
    }
    k -= n;
    long long d = k % (2 * (m - 1));
    if (d >= m - 1) printf("%lld %lld\n", n - (k / (m - 1)), m - (k % (m - 1)));
    else printf("%lld %lld\n", n - (k / (m - 1)), 2 + k % (m - 1));
    return 0;
}