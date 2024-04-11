#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, a[200001], pre[200001];
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == a[i - 1])
        {
            pre[i] = pre[i - 1];
        }
        else
        {
            pre[i] = i - 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (a[r] != x)
        {
            printf("%d\n", r);
        }
        else
        {
            if (pre[r] < l)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", pre[r]);
            }
        }
    }
    return 0;
}