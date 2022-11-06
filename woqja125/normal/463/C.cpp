#include<stdio.h>
int dat[2001][2001];
long long sum[10000];
long long sum2[10000];
int main()
{
    int n, i, j, x1=1, x2=1, y1=1, y2=2;
    long long max1 = 0, max2 = 0;
    scanf("%d", &n);
    for(i=1; i<=n; i++)for(j=1; j<=n; j++)
        scanf("%d", &dat[i][j]);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            sum[i+j] += dat[i][j];
            sum2[i-j+5000] += dat[i][j];
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            long long t = sum[i+j] + sum2[i-j+5000] - dat[i][j];
            if((i+j)%2)
            {
                if(max1 < t)
                {
                    x1 = i; y1 = j;
                    max1 = t;
                }
            }
            else
            {
                if(max2 < t)
                {
                    x2 = i; y2 = j;
                    max2 = t;
                }
            }
        }
    }
    printf("%I64d\n%d %d %d %d", max1+max2, x1, y1, x2, y2);
    return 0;
}