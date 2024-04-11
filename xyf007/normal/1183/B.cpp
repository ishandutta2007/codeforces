#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, q, k, a[100001];
int main()
{
    scanf("%d", &q);
    while (q--)
    {
        int max = 0, min = 2e9;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > max)
            {
                max = a[i];
            }
            if (a[i] < min)
            {
                min = a[i];
            }
        }
        if (max - min > 2 * k)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", min + k);
        }
    }
    return 0;
}