#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int x[25], y[25];
int g[25][25];
int mask[1<<24], prv[1<<24];

int main()
{
    int n, i, i1, j, k, j1, k1,  bi=1<<29, m[25], top, tmp;
    scanf("%d %d", &x[0], &y[0]);
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        scanf("%d %d", &x[i], &y[i]);
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            g[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    for(i=1; i<(1<<n); i++)
    {
        for(j=n-1; !(i&(1<<j)); j--);
        mask[i]=mask[i^(1<<j)]+2*g[0][j+1];
        prv[i]=i^(1<<j);
        for(k=0; k<j; k++)
            if (i&(1<<k))
            {
                if (mask[i]>mask[i^(1<<j)^(1<<k)]+g[0][j+1]+g[0][k+1]+g[j+1][k+1])
                {
                    mask[i]=mask[i^(1<<j)^(1<<k)]+g[0][j+1]+g[0][k+1]+g[j+1][k+1];
                    prv[i]=i^(1<<j)^(1<<k);
                }
            }
    }
    printf("%d\n", mask[(1<<n)-1]);
    printf("0 ");
    i=(1<<n)-1;
    while(i!=0)
    {
        i1=prv[i];
        j=i^i1;
        for(k=0; k<n; k++)
            if (j&(1<<k)) 
            {
                j^=(1<<k);
                break;
            }
        k++;
        for(i1=j, j=0; i1; j++)
            i1>>=1;
        printf("%d ", k);
        if (j) printf("%d ", j);
        printf("0 ");
        i=prv[i];
    }
}