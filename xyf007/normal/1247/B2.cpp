#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m, d, a[200001], cnt[1000001];
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
        scanf("%d%d%d", &n, &m, &d);
        int ans = d, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= d; i++)
        {
            if (!cnt[a[i]])
            {
                sum++;
            }

            cnt[a[i]]++;
        }
        checkmin(ans, sum);
        for (int i = 1; i + d <= n; i++)
        {
            cnt[a[i]]--;
            if (!cnt[a[i]])
            {
                sum--;
            }
            if (!cnt[a[i + d]])
            {
                sum++;
            }
            cnt[a[i + d]]++;
            checkmin(ans, sum);
        }
        for (int i = n - d + 1; i <= n; i++)
        {
            cnt[a[i]]--;
        }
        printf("%d\n", ans);
    }
    return 0;
}