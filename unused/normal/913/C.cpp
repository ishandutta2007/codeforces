#include <bits/stdc++.h>
using namespace std;

int c[33];

int main()
{
    int n, l;
    scanf("%d%d", &n, &l);

    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    for (int i = 1; i < n; i++)
    {
        c[i] = min(c[i], c[i - 1] * 2);
    }

    long long ans = 1e18;
    long long now = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        while (l >= (1 << i))
        {
            l -= 1 << i;
            now += c[i];
        }
        ans = min(ans, now + c[i]);
    }
    printf("%lld\n", min(ans, now));
}