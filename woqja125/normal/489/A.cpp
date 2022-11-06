#include<stdio.h>
int a[3001], ans[3001][2];
int main()
{
    int n, i, j, c = 0;
    scanf("%d", &n);
    for(i=1; i<=n; i++)scanf("%d", a+i);
    for(i=1; i<n; i++)
    {
        int m = i;
        for(j=i+1; j<=n; j++)
        {
            if(a[j] < a[m]) m = j;
        }
        if(m != i)
        {
            ans[++c][0] = i;
            ans[c][1] = m;
            a[m] = a[i];
        }
    }
    printf("%d\n", c);
    for(i=1; i<=c; i++)printf("%d %d\n", ans[i][0]-1, ans[i][1]-1);
    return 0;
}