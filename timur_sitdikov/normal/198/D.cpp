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

int v[100][100][100];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, i, j, k, mn, dif, f, s;
    scanf("%d", &n);
    if (n==1)
    {
        printf("1");
        return 0;
    }
    v[1][1][2]=1;
    v[1][1][1]=2;
    v[1][2][1]=3;
    v[1][2][2]=4;
    v[2][2][2]=5;
    v[2][2][1]=6;
    v[2][1][1]=7;
    v[2][1][2]=8;
    for(i=3; i<=n; i++)
    {
        if (i&1)
        {
            f=v[1][1][i-1]-1;
            for(j=1; j<=i; j++)
                v[1][j][i]=f--;
            for(j=i-1; j>0; j--)
                v[1][i][j]=f--;
        }
        else
        {
            f=v[1][i-1][1]-1;
            for(j=1; j<=i; j++)
                v[1][i][j]=f--;
            for(j=i-1; j>0; j--)
                v[1][j][i]=f--;
        }
        f=v[i-1][1][i-1]+1;
        if (!(i&1))
        {
            for(j=1; j<i; j++)
            {
                if (j&1)
                    for(k=i-1; k>0; k--)
                        v[i][j][k]=f++;
                else
                    for(k=1; k<i; k++)
                        v[i][j][k]=f++;
            }
            for(k=i; k>1; k--)
                v[k][i][1]=f++;
            for(k=2; k<=i; k++)
            {
                if (k&1)
                {
                    for(j=1; j<=i; j++)
                        v[k][j][i]=f++;
                    for(j=i-1; j>1; j--)
                        v[k][i][j]=f++;
                }
                else
                {
                    for(j=2; j<=i; j++)
                        v[k][i][j]=f++;
                    for(j=i-1; j>0; j--)
                        v[k][j][i]=f++;
                }
            }
        }
        else
        {
            for(j=1; j<i; j++)
            {
                if (j&1)
                    for(k=i-1; k>0; k--)
                        v[i][j][k]=f++;
                else
                    for(k=1; k<i; k++)
                        v[i][j][k]=f++;
            }
            for(k=i; k>1; k--)
            {
                if (k&1)
                    for(j=i-1; j>0; j--)
                        v[k][i][j]=f++;
                else 
                    for(j=1; j<i; j++)
                        v[k][i][j]=f++;
            }
            for(k=i; k>0; k--)
            {
                if (k&1)
                    for(j=2; j<=i; j++)
                        v[j][k][i]=f++;
                else 
                    for(j=i; j>1; j--)
                        v[j][k][i]=f++;
            }
        }
    }
    mn=1;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            for(k=1; k<=n; k++)
                if (v[i][j][k]<mn) mn=v[i][j][k];
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            for(k=1; k<=n; k++)
                v[i][j][k]+=1-mn;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            for(k=1; k<=n; k++)
                printf("%d ", v[i][j][k]);
            putchar('\n');
        }
        putchar('\n');
    }

}