#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, a[100001];
long long Abs(long long x)
{
    return x >= 0 ? x : -x;
}
int main(int argc, char const *argv[])
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    long long ans = 0, tmp = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (!a[i])
        {
            tmp++;
            continue;
        }
        if (Abs(a[i] - 1LL) < Abs(a[i] + 1LL))
        {
            ans += Abs(a[i] - 1LL);
        }
        else
        {
            ans += Abs(a[i] + 1LL);
            sum++;
        }
        
    }
    if (!tmp && sum & 1)
    {
        printf("%lld", ans + 2);
    }
    else
    {
        printf("%lld", ans + tmp);
    }
    return 0;
}