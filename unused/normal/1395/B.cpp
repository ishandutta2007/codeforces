#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, sx, sy;
    scanf("%d%d%d%d",&n,&m,&sx,&sy);
    
    for (int i = sx; i >= 1; i--) printf("%d %d\n", i, sy);
    for (int i = sx + 1; i <= n; i++) printf("%d %d\n", i, sy);
    int last = n;
    for (int j = sy + 1; j <= m; j++)
    {
        if (last == n)
        {
            for (int i = n; i >= 1; i--) printf("%d %d\n", i, j);
            last = 1;
        }
        else
        {
            for (int i = 1; i <= n; i++) printf("%d %d\n", i, j);
            last = n;
        }
    }
    for (int j = 1; j < sy; j++)
    {
        if (last == n)
        {
            for (int i = n; i >= 1; i--) printf("%d %d\n", i, j);
            last = 1;
        }
        else
        {
            for (int i = 1; i <= n; i++) printf("%d %d\n", i, j);
            last = n;
        }
    }
}