#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[8001], sum[8001];
bool vis[64000001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                vis[sum[j] - sum[i - 1]] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[a[i]])
            {
                ans++;
            }
        }
        printf("%d\n", ans);
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                vis[sum[j] - sum[i - 1]] = 0;
            }
        }
    }
    return 0;
}