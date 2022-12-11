#include <bits/stdc++.h>
using namespace std;

int dat[100005];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> dat[i];

    int g = 0;
    for (int i = 0; i < n; i++) g = gcd(g, dat[i]);

    if (g > 1)
    {
        printf("YES\n0\n");
        return 0;
    }

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (dat[i-1] & 1)
        {
            if (dat[i] & 1)
            {
                ++ans;
            }
            else ans += 2;

            dat[i] = 0;
        }
        else if (i == n - 1)
        {
            if (dat[i] & 1) ans += 2;
        }
    }

    printf("YES\n%d\n", ans);
}