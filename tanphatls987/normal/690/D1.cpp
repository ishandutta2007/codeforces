#include <bits/stdc++.h>

using namespace std;

char a[110][110];

int main()
{
    int m, n;
    scanf("%d%d\n", &m, &n);
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
            scanf("%c", &a[i][j]);
        scanf("\n");
    }
    a[m][0] = '.';
    int res = 0;
    for(int i=1; i<=n; i++)
    {
        if (a[m][i] == 'B')
            res += (a[m][i-1] == '.');
    }
    printf("%d\n", res);
    return 0;
}