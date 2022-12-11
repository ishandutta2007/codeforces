#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (;;) {
    int n;
    if (scanf("%d",&n) != 1) break;
    int ans = 2e9;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, i * 2 + (n + i - 1) / i * 2);
    }
    printf("%d\n", ans);
    }
}