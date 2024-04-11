#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = (int)2e5 + 100;
int n;
int a[N];
int g[N];
ll ans = 0;
bool b[N];

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x % y));
}

void calc(int l, int d)
{
    for (int x = d; x <= l; x += d)
    {
        if (g[x] != d) continue;
        if (l == n)
            ans += l;
        else
            ans += l - x + 1;
    }
    return;
}

void solve(int d)
{
    for (int i = 0; i < d; i++)
    {
        int x = 0;
        for (int j = i; j < n; j += d)
            x = max(x, a[j]);
        for (int j = i; j < n; j += d)
            b[j] = (a[j] == x);
    }
    int fst = 0;
    while(fst < n && b[fst]) fst++;
    int idx = fst;
    int len = 0;
    while(idx < n)
    {
        if (!b[idx])
        {
            calc(len, d);
            len = 0;
        }
        else
            len++;
        idx++;
    }
    calc(len + fst, d);
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bool eq = true;
    for (int i = 0; i < n; i++)
        eq &= a[0] == a[i];
    if (eq)
    {
        printf("%lld\n", (ll)n * (n - 1));
        return 0;
    }
    for (int i = 1; i <= n; i++)
        g[i] = gcd(i, n);
    for (int d = 1; d < n; d++)
    {
        if (n % d != 0) continue;
        solve(d);
    }
    printf("%lld\n", ans);

    return 0;
}