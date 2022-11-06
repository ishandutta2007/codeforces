#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k, l;
    scanf("%lld%lld%lld%lld", &n, &m, &k, &l);
    long long x = (l + k + m - 1) / m;
    if (1.0 * m * x > n) puts("-1");
    else if (l > n - k) puts("-1");
    else printf("%lld\n", x);
    return 0;
}