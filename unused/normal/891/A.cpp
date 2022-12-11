#include <bits/stdc++.h>
using namespace std;

int x[2005];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&x[i]);

    int one = 0;
    for (int i = 0; i < n; i++) if (x[i] == 1) ++one;
    if (one)
    {
        printf("%d\n", n - one);
        return 0;
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int now = x[i];
        for (int j = i; j < n; j++)
        {
            now = gcd(now, x[j]);
            if (now == 1) ans = min(ans, n - 1 + j - i);
        }
    }

    if (ans == INT_MAX) ans = -1;
    printf("%d\n", ans);
}