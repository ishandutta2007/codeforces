#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, A, R, M, h[100001], sum[100001];
void checkmin(long long &x, long long y)
{
    if (x > y)
    {
        x = y;
    }
}
long long solve(long long H)
{
    int pos = lower_bound(h + 1, h + n + 1, H) - h - 1;
    long long t1 = H * pos - sum[pos], t2 = sum[n] - sum[pos] - H * (n - pos), tmp = min(t1, t2);
    t1 -= tmp;
    t2 -= tmp;
    return tmp * M + t1 * A + t2 * R;
}
int main(int argc, char const *argv[])
{
    scanf("%lld%lld%lld%lld", &n, &A, &R, &M);
    checkmin(M, A + R);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &h[i]);
    }
    sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + h[i];
    }
    long long ans = 1e18;
    checkmin(ans, solve(sum[n] / n));
    checkmin(ans, solve(sum[n] / n + 1));
    for (int i = 1; i <= n; i++)
    {
        checkmin(ans, solve(h[i]));
    }
    printf("%lld", ans);
    return 0;
}