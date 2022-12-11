#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i * 1234567 <= n; i++)
    {
        int z = n - i * 1234567;

        for (int j = 0; j * 123456 <= z; j++)
        {
            int y = z - j * 123456;
            if (y % 1234 == 0) { printf("YES\n"); return 0; }
        }
    }
    printf("NO\n");
}