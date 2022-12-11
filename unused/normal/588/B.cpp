#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    scanf("%lld",&n);
    for (int i = 2; i <= 1000001; i++)
    {
        while (n % (i * 1ll * i) == 0)
        {
            n /= i;
        }
    }
    printf("%lld\n", n);
}