#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, a[1000001], sum, ans[1000001], add;
int main(int argc, const char *argv[])
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (n == 1)
    {
        printf("%lld\n", a[1]);
        return 0;
    }
    long long tot = (n - 1) * n / 2;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i - 1;
    }
    sum -= tot;
    add = sum / n;
    for (int i = 1; i <= n; i++)
    {
        a[i] += add;
    }
    sum %= n;
    for (int i = 1; i <= sum; i++)
    {
        a[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", a[i]);
    }
    return 0;
}