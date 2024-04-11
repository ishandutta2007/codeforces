#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[101];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        bool f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!(a[i] % 2))
            {
                printf("1\n%d\n", i);
                f = 1;
                break;
            }
        }
        if (!f)
        {
            if (n == 1)
            {
                printf("-1\n");
            }
            else
            {
                printf("2\n1 2\n");
            }
        }
    }
    return 0;
}