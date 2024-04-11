#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, ans, a[1001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[n + 1] = 1001;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n + 1; j++)
        {
            if (j - i == a[j] - a[i])
            {
                checkmax(ans, j - i - 1);
            }
        }
    }
    printf("%d", ans);
    return 0;
}