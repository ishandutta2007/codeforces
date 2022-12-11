#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long k, x = 1;
    scanf("%d %lld", &n, &k);
    for(int i = 0; i < n; i++)
    {
        long long c;
        scanf("%lld", &c);
        x = __gcd(k, x * c / __gcd(x, c));
    }
    puts(x == k ? "Yes" : "No");
}