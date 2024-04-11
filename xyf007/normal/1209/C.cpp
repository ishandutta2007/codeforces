#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[200001], b[200001], ans[200001];
bool f[200001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%01d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int l = 1;
        for (int i = 1; i <= n; i++)
        {
            if (f[i])
            {
                continue;
            }
            if (a[i] == b[l])
            {
                f[i] = 1;
                ans[i] = 1;
                l++;
            }
            if (l == n + 1)
            {
                break;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (f[i])
            {
                continue;
            }
            if (a[i] == b[l])
            {
                f[i] = 1;
                ans[i] = 2;
                l++;
            }
            if (l == n + 1)
            {
                break;
            }
        }
        if (l != n + 1)
        {
            printf("-\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}