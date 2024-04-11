#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int k = 0;
    long long ans = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            if((i * i + j * j) % m == 0) k++;
    ans += k * 1LL * (n / m) * (n / m);
    k = 0;
    for(int i = 1; i <= n % m; i++)
        for(int j = 1; j <= m; j++)
            if((i * i + j * j) % m == 0) k++;
    ans += k * 2LL * (n / m);
    k = 0;
    for(int i = 1; i <= n % m; i++)
        for(int j = 1; j <= n % m; j++)
            if((i * i + j * j) % m == 0) k++;
    ans += k;
    printf("%lld\n", ans);
}