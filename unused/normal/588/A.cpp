#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int price = 1e9;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        price = min(price, b);
        ans += a * price;
    }
    printf("%d\n", ans);
}