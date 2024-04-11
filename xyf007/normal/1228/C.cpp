#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const long long MOD = 1e9 + 7;
long long x, n;
long long ksm(long long a, long long b)
{
    long long s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = s * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    scanf("%lld%lld", &x, &n);
    long long ans = 1, sz = sqrt(x);
    for (long long i = 2; i <= sz + 1; i++)
    {
        if (!(x % i))
        {
            long long sum = 0, tmp = n / i;
            while (tmp)
            {
                sum += tmp;
                tmp /= i;
            }
            ans = ans * ksm(i, sum) % MOD;
            while (!(x % i))
            {
                x /= i;
            }
        }
    }
    if (x > 2)
    {
        long long sum = 0, tmp = n / x;
        while (tmp)
        {
            sum += tmp;
            tmp /= x;
        }
        ans = ans * ksm(x, sum) % MOD;
    }
    printf("%lld", ans);
    return 0;
}