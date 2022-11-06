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

int del[2]={2,5};
int m[2][1005][1005], bi=1000000, top=0;
char prv[2][1005][1005], is_good[1005][1005], stk[2500];

int main()
{   
    int i, j, n, k, v, mn;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d", &v);
            if (v)
                for(k=0; k<2; k++)
                    for(; !(v%del[k]); v/=del[k])
                        m[k][i][j]++;
            else 
            {
                is_good[i][j]=1;
                for(k=0; k<2; k++)
                    m[k][i][j]=bi;
            }
        }
    for(k=0; k<2; k++)
    {
        prv[k][0][0]=-1;
        for(i=1; i<n; i++)
        {
            m[k][i][0]+=m[k][i-1][0];
            prv[k][i][0]=1;
            m[k][0][i]+=m[k][0][i-1];
            prv[k][0][i]=0;
        }
        for(i=1; i<n; i++)
            for(j=1; j<n; j++)
            {
                if (m[k][i-1][j]<m[k][i][j-1])
                {
                    m[k][i][j]+=m[k][i-1][j];
                    prv[k][i][j]=1;
                }
                else
                {
                    m[k][i][j]+=m[k][i][j-1];
                    prv[k][i][j]=0;
                }
            }
    }
    if (m[0][n-1][n-1]<m[1][n-1][n-1]) k=0;
    else k=1;
    mn=m[k][n-1][n-1];
    if (mn>=1)
    {
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if (is_good[i][j]) goto l1;
        goto l;
l1:     for(k=n-2; k>=i; k--)
            stk[top++]=1;
        for(k=n-2; k>=j; k--)
            stk[top++]=0;
        for(k=0; k<i; k++)
            stk[top++]=1;
        for(k=0; k<j; k++)
            stk[top++]=0;
        printf("1\n");
        for(i=top-1; i>=0; i--)
            putchar(stk[i]? 'D': 'R');
        return 0;
    }
l:  for(i=n-1, j=n-1; prv[k][i][j]!=-1; )
    {
        stk[top++]=prv[k][i][j];
        if (prv[k][i][j]) i--;
        else j--;
    }
    printf("%d\n", m[k][n-1][n-1]);
    for(i=top-1; i>=0; i--)
        putchar(stk[i]? 'D': 'R');
}