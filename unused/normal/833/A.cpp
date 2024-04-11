#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        long long X = pow((long double)(a * 1ll * b), 1.0L / 3);
        for (int i = -100; i <= 100; i++)
        {
            if ((X + i) * (X + i) * (X + i) == a * 1ll * b)
            {
                X += i;
                break;
            }
        }

        if (X * X * X != a * 1ll * b || a % X || b % X)
        {
            printf("No\n");
            continue;
        }
        else printf("Yes\n");
    }
}