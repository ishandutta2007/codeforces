#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[101], b[101];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    int t1 = 0, t2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] && !b[i])
        {
            t1++;
        }
        if (!a[i] && b[i])
        {
            t2++;
        }
    }
    if (!t1)
    {
        printf("-1");
        return 0;
    }
    else
    {
        if ((t2 + 1) % t1)
        {
            printf("%d", (t2 + 1) / t1 + 1);
        }
        else
        {
            printf("%d", (t2 + 1) / t1);
        }
    }
    return 0;
}