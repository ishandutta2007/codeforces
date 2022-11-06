#include<stdio.h>
int n, m;
int w[501], b[1001], l[501], v[501];
int main()
{
    int i, j, ans = 0, c = 0;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)scanf("%d", w+i);
    for(i=1; i<=m; i++)scanf("%d", b+i);
    for(i=1; i<=m; i++)
    {
        if(v[b[i]] == 0)
        {
            for(j=1; j<=c; j++) ans += w[l[j]];
            v[b[i]] = 1;
            l[++c] = b[i];
        }
        else
        {
            for(j=1; j<=c; j++) if(l[j] == b[i]) break;
            for(; j<c; j++)
            {
                l[j] = l[j+1];
                ans += w[l[j]];
            }
            l[j] = b[i];
        }
    }
    printf("%d", ans);
    return 0;
}