#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m, a[200001], b[200001], maxx[200001], minn[200001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &b[i]);
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        long long ans = 0;
        int tmp = 1;
        for (int i = 1; i <= m; i++)
        {
            maxx[i] = minn[i] = a[n - i + 1];
        }
        for (int i = m; i >= 1 && b[i] > 1; i--)
        {
            minn[i] = a[tmp];
            tmp += b[i] - 1;
        }
        for (int i = 1; i <= m; i++)
        {
            ans += maxx[i] + minn[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}