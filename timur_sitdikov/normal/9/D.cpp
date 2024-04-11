#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long v[36][36];

int log2(int v)
{
    int i=1, ans=0;
    for(; i<=v; ans++, i<<=1);
    return ans-1;
}

int main()
{   

    long long n, h, ans=0, i, j, i1, j1, i2, j2;
    scanf("%lld %lld", &n, &h);
    v[0][0]=1;
    for(i=1; i<=n; i++)
        for(j=log2(i); j<=i; j++)
        {
            for(i1=0; i1<i; i1++)
                for(j2=0; j2<j-1; j2++)
                    v[i][j]+=v[i1][j-1]*v[i-1-i1][j2];
            for(i2=0; i2<i; i2++)
                for(j1=0; j1<j; j1++)
                    v[i][j]+=v[i-1-i2][j1]*v[i2][j-1];
        }
    for(i=h; i<=n; i++) ans+=v[n][i];
    printf("%lld", ans);
}