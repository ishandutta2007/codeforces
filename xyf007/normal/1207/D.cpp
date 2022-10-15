#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define see(x) cout << #x << ' ' << x << endl
using namespace std;
const long long MOD = 998244353;
struct node
{
    long long l, r;
} a[300001];
long long n, sum[300001];
void init()
{
    sum[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] * i % MOD;
    }
}
bool cmp1(node a, node b)
{
    if (a.l == b.l)
    {
        return a.r < b.r;
    }
    return a.l < b.l;
}
bool cmp2(node a, node b)
{
    return a.r < b.r;
}
int main(int argc, char const *argv[])
{
    scanf("%lld", &n);
    init();
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &a[i].l, &a[i].r);
    }
    long long ans = sum[n], cnt = 1, tmp = 1;
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i < n; i++)
    {
        if (a[i].l == a[i + 1].l)
        {
            cnt++;
        }
        else
        {
            tmp = tmp * sum[cnt] % MOD;
            cnt = 1;
        }
    }
    tmp = tmp * sum[cnt] % MOD;
    ans = (ans + MOD - tmp) % MOD;
    cnt = 1;
    tmp = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].r > a[i + 1].r)
        {
            goto nxt;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i].l == a[i + 1].l && a[i].r == a[i + 1].r)
        {
            cnt++;
        }
        else
        {
            tmp = tmp * sum[cnt] % MOD;
            cnt = 1;
        }
    }
    tmp = tmp * sum[cnt] % MOD;
    ans = (ans + tmp) % MOD;
    nxt:;
    sort(a + 1, a + n + 1, cmp2);
    cnt = 1;
    tmp = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].r == a[i + 1].r)
        {
            cnt++;
        }
        else
        {
            tmp = tmp * sum[cnt] % MOD;
            cnt = 1;
        }
    }
    tmp = tmp * sum[cnt] % MOD;
    ans = (ans + MOD - tmp) % MOD;
    printf("%lld", ans);
    return 0;
}