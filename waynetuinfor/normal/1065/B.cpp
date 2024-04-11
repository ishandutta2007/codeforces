#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m; scanf("%lld%lld", &n, &m);
    long long a = max(0ll, n - m * 2);
    long long b = 0;
    while (b * (b - 1) / 2 < m) ++b;
    printf("%lld %lld\n", a, max(0ll, n - b));
}