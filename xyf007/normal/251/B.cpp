#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k, a[2][105][105], p[105], s[105];
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        a[0][0][i] = a[1][0][i] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[0][i][j] = a[0][i - 1][p[j]];
            a[1][i][p[j]] = a[1][i - 1][j];
        }
    }
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i <= k; i++)
    {
        bool f = 1;
        for (int j = 1; j <= n; j++)
        {
            if (a[0][i][j] != s[j])
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            pos1 = i;
            break;
        }
    }
    for (int i = 0; i <= k; i++)
    {
        bool f = 1;
        for (int j = 1; j <= n; j++)
        {
            if (a[1][i][j] != s[j])
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            pos2 = i;
            break;
        }
    }
    if (pos1 == -1)
    {
        if (pos2 != -1 && !((k - pos2) % 2))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    else
    {
        if (!pos1)
        {
            if (!k)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if (pos1 == 1)
            {
                if (pos2 != 1)
                {
                    if (!((k - pos1) % 2) || (pos2 != -1 && !((k - pos2) % 2)))
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                }
                else
                {
                    if (k == 1)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                }
            }
            else
            {
                if (!((k - pos1) % 2))
                {
                    printf("YES\n");
                }
                else
                {
                    if (pos2 != -1 && !((k - pos2) % 2))
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                }
            }
        }
    }
    return 0;
}