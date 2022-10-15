#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
long long n, m, q;
int main(int argc, char const *argv[])
{
    scanf("%lld%lld%lld", &n, &m, &q);
    long long GCD = __gcd(n, m), len1 = n / GCD, len2 = m / GCD;
    while (q--)
    {
        long long s1, s2, e1, e2, t1, t2;
        scanf("%lld%lld%lld%lld", &s1, &s2, &e1, &e2);
        if (s1 == 1)
        {
            t1 = (s2 - 1) / len1;
        }
        else
        {
            t1 = (s2 - 1) / len2;
        }
        if (e1 == 1)
        {
            t2 = (e2 - 1) / len1;
        }
        else
        {
            t2 = (e2 - 1) / len2;
        }
        if (t1 == t2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}