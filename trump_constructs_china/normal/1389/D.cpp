#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long t, n, k, l1, r1, l2, r2;
int main(int argc, char const *argv[])
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld%lld%lld", &n, &k, &l1, &r1, &l2, &r2);
        if (l1 > l2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        else
        {
            if (l1 == l2 && r1 > r2)
            {
                swap(r1, r2);
            }
        }
        if (r1 < l2)
        {
            long long t = l2 - r1, x = r2 - l1;
            if (k <= n * x)
            {
                long long tt = k / x, ans = tt * (t + x), le = k - tt * x;
                if (le < t && tt)
                {
                    ans += 2 * le;
                }
                else
                {
                    ans += le + t;
                }
                printf("%lld\n", ans);
            }
            else
            {
                printf("%lld\n", n * (t + x) + 2 * (k - n * x));
            }
        }
        else
        {
            if (r1 < r2)
            {
                long long len = r1 - l2;
                k -= n * len;
                if (k <= 0)
                {
                    printf("0\n");
                }
                else
                {
                    long long le = r2 - l1 - len;
                    if (n * le >= k)
                    {
                        printf("%lld\n", k);
                    }
                    else
                    {
                        printf("%lld\n", n * le + 2 * (k - n * le));
                    }
                }
            }
            else
            {
                long long len = r2 - l2;
                k -= n * len;
                if (k <= 0)
                {
                    printf("0\n");
                }
                else
                {
                    long long le = r1 - l1 - len;
                    if (n * le >= k)
                    {
                        printf("%lld\n", k);
                    }
                    else
                    {
                        printf("%lld\n", n * le + 2 * (k - n * le));
                    }
                }
            }
        }
    }
    return 0;
}