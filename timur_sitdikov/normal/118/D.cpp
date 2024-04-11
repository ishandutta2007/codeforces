#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int m0[201][101][11], m1[201][101][11];

int main()
{   
   
    int n1, n2, n, k1, k2, i, j, k, l1, l2, ans=0, lim, d=100000000;
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    n=n1+n2;
    m0[1][1][1]=1; m1[1][0][1]=1;
    for(i=2; i<=n; i++)
    {
        lim=min(i, n1);
        for(j=0; j<=lim; j++)
        {
            if (j)
            {
                for(k=1; k<=k2; k++)
                {
                    m0[i][j][1]+=m1[i-1][j-1][k];
                    if (m0[i][j][1]>=d) m0[i][j][1]-=d;
                }
                for(k=2; k<=k1; k++)
                {
                    m0[i][j][k]=m0[i-1][j-1][k-1];
                    if (m0[i][j][k]>=d) m0[i][j][k]-=d;
                }
            }
            for(k=1; k<=k1; k++)
            {
                m1[i][j][1]+=m0[i-1][j][k];
                if (m1[i][j][1]>=d) m1[i][j][1]-=d;
            }
            for(k=2; k<=k2; k++)
            {
                m1[i][j][k]=m1[i-1][j][k-1];
                if (m1[i][j][k]>=d) m1[i][j][k]-=d;
            }
        }
    }
    for(i=0; i<=k1; i++)
    {
        ans+=m0[n][n1][i];
        if (ans>=d) ans-=d;
    }
    for(i=0; i<=k2; i++)
    {
        ans+=m1[n][n1][i];
        if (ans>=d) ans-=d;
    }
    printf("%d\n", ans);
}