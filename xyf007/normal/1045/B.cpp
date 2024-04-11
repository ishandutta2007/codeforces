#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int base = 131;
int n, m, a[200001], b[200001], ans[200001], tot;
unsigned long long fac[200001], hash1[200001], hash2[200001];
unsigned long long calc1(int l, int r)
{
    return hash1[r] - hash1[l - 1] * fac[r - l + 1];
}
unsigned long long calc2(int l, int r)
{
    return hash2[l] - hash2[r + 1] * fac[r - l + 1];
}
bool check(int l, int r)
{
    return calc1(l, r) == calc2(l, r);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        b[i] = a[i + 1] - a[i];
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * base;
    }
    for (int i = 1; i < n; i++)
    {
        hash1[i] = hash1[i - 1] * base + b[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        hash2[i] = hash2[i + 1] * base + b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        bool f = 1;
        if (i > 1)
        {
            f &= check(1, i - 1);
        }
        if (i < n)
        {
            f &= a[1] + a[i] + m == a[i + 1] + a[n];
            if (i < n - 1)
            {
                f &= check(i + 1, n - 1);
            }
        }
        if (f)
        {
            ans[++tot] = (a[1] + a[i]) % m;
        }
    }
    sort(ans + 1, ans + tot + 1);
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}