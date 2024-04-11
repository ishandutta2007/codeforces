#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[200001];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        int maxx = a[1], l = 1, r = 2, minn = a[1];
        long long ans = 0;
        while (l <= n)
        {
            while (r <= n && a[r] < maxx)
            {
                checkmin(minn, a[r]);
                if (a[r - 1] <= a[r] && a[r + 1] < a[r])
                {
                    break;
                }
                r++;
            }
            ans += maxx - minn;
            l = r;
            maxx = minn = a[l];
            r++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}