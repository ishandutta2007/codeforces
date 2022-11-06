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
#include <complex>
using namespace std;
#define pb push_back

const int maxn=105;
int vv[maxn][maxn], vv1[maxn][maxn];

int solve(int n, int m)
{
    int i, j, tmp;
    if (n==1)
    {
        if (m>=2 && m <=3)
            return 0;
    }
    if (n==2 && m==2)
        return 0;
    if (n==1 && m==4)
    {
        vv[0][0]=2;
        vv[0][1]=4;
        vv[0][2]=1;
        vv[0][3]=3;
        return 1;
    }
    if (n==2 && m==3)
    {
        tmp=3;
        for(j=0; j<3; j++)
        {
            vv[0][j]=tmp;
            tmp=(tmp+2)%6;
        }
        tmp=6;
        for(j=0; j<3; j++)
        {
            vv[1][j]=tmp;
            tmp=(tmp+2)%6;
        }
        return 1;
    }
    tmp=1;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (!((i+j)&1))
                vv[i][j]=tmp++;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if ((i+j)&1)
                vv[i][j]=tmp++;
    return 1;
}

void transpose(int n, int m)
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            vv1[j][i]=vv[i][j];
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            vv[j][i]=vv1[j][i];
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, d=100;
    cin >> n >> m;
    /*for(n=1; n<=d; n++)
        for(m=1; m<=d; m++)
        {
            if (solve(n, m))
            {
                for(i=1; i<n; i++)
                    for(j=0; j<m; j++)
                        if (abs(vv[i][j]-vv[i-1][j])==1)
                            i=i;
                for(i=0; i<n; i++)
                    for(j=1; j<m; j++)
                        if (abs(vv[i][j]-vv[i][j-1])==1)
                            i=i;

            }

        }*/
    if (n>m)
    {
        if (!solve(m, n))
        {
            printf("-1");
            return 0;
        }
        transpose(m, n);
    }
    else if (!solve(n, m))
        {
            printf("-1");
            return 0;
        }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%d ", vv[i][j]);
        putchar('\n');
    }
}