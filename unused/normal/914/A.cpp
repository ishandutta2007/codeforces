#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int ans = -1000000000;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        if (x < 0) ans = max(ans, x);
        else if ((int)sqrt(x) * (int)sqrt(x) != x) ans = max(ans, x);
    }
    printf("%d\n", ans);
}