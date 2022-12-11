#include <bits/stdc++.h>
using namespace std;

bool lucky(int x)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 3; i++, x/=10) sum1 += x%10;
    for (int i = 0; i < 3; i++, x/=10) sum2 += x%10;
    return sum1 == sum2;
}

int diff(int x, int y)
{
    int ans = 0;
    for (int i = 0; i < 6; i++, x/=10, y/=10) ans += x%10 != y%10;
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    int ans = 1e9;

    for (int i = 0; i < 1000000; i++)
    {
        if (lucky(i) == false) continue;
        ans = min(ans, diff(n, i));
    }

    printf("%d\n", ans);
}