#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int t, n, m, k, a[101];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        bool f = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] >= max(a[i + 1] - k, 0))
            {
                if (a[i + 1] - k < 0)
                {
                    m += a[i];
                }
                else
                {
                    m += a[i] - a[i + 1] + k;
                }
                continue;
            }
            if (m < a[i + 1] - k - a[i])
            {
                f = 0;
                break;
            }
            m -= a[i + 1] - k - a[i];
        }
        if (f)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}