#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = (int)1e6 + 5;
int n, k;
int fenv[N];

void add(int p, int x)
{
    for (; p < n; p |= p + 1)
        fenv[p] += x;
    return;
}
int getSum(int r)
{
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += fenv[r];
    return res;
}

int solve(int l, int r)
{
    if (l < 0)
        return getSum(n - 1) - getSum(n + l - 1) + getSum(r);
    if (r >= n)
        return getSum(n - 1) - getSum(l - 1) + getSum(r - n + 1);
    return getSum(r) - getSum(l - 1);
}

int main()
{
    scanf("%d%d", &n, &k);
    k = min(k, n - k);
    int x = 0;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans += 1 + solve(x - k + 1, x + k - 1);
        printf("%lld ", ans);
        add(x, 1);
        x += k;
        x %= n;
    }
    printf("\n");

    return 0;
}