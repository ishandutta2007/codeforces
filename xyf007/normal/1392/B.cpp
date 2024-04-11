#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, k, a[200001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        int maxx = -2e9;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            checkmax(maxx, a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = maxx - a[i];
        }
        maxx = -2e9;
        for (int i = 1; i <= n; i++)
        {
            checkmax(maxx, a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (k & 1)
            {
                printf("%d ", a[i]);
            }
            else
            {
                printf("%d ", maxx - a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}