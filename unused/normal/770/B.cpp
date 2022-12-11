#include <bits/stdc++.h>
using namespace std;

int sum(long long z)
{
    int ret = 0;
    while (z) ret += z % 10, z /= 10;
    return ret;
}

int main()
{
    long long z;
    scanf("%lld",&z);
    auto ans = make_pair(sum(z), z);
    for (long long i = 10; i <= z; i *= 10)
    {
        long long zz = z - z % i - 1;
        if (zz <= 0) continue;
        ans = max(ans, make_pair(sum(zz), zz));
        if (i == (long long)1e18) break;
    }
    printf("%lld\n", ans.second);
}