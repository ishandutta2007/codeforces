#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    scanf("%lld%lld",&n,&m);
    long long mod = 1;
    while (n && mod <= m)
        --n, mod *= 2;
    printf("%lld\n", m % mod);
}