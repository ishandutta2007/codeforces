#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

int main() {
    long long a, b; scanf("%lld %lld", &a, &b);
    long long c = a + b;
    long long ans = inf;
    vector<long long> adv, af;
    for (long long i = 1; i * i <= a; ++i) if (a % i == 0) adv.push_back(i);
    vector<long long> bdv, bf;
    for (long long i = 1; i * i <= b; ++i) if (b % i == 0) bdv.push_back(i);
    int ap = 0, bp = 0;
    long long mai = inf, mbi = inf;
    for (long long i = 1; i * i <= c; ++i) if (c % i == 0) {
         while (ap < adv.size() && adv[ap] <= i) mai = min(mai, a / adv[ap]), ++ap;
         while (bp < bdv.size() && bdv[bp] <= i) mbi = min(mbi, b / bdv[bp]), ++bp;
         if (mai <= c / i || mbi <= c / i) ans = min(ans, (i + c / i) * 2);
    }
    printf("%lld\n", ans);
    return 0;
}