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
#define mp make_pair
#define point complex<double>

const int maxn=6, inf=1000000000;
int g[maxn][maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, k, n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (x1==x2 && y1==y2)
    {
        cout << 0;
        return 0;
    }
    for(i=0; i<maxn; i++)
        for(j=i+1; j<maxn; j++)
            g[i][j]=g[j][i]=inf;
    g[1][2]=g[2][1]=n;
    g[2][3]=g[3][2]=n;
    g[3][4]=g[4][3]=n;
    g[4][1]=g[1][4]=n;
    if (x1==0)
    {
        g[0][1]=g[1][0]=y1;
        g[0][4]=g[4][0]=n-y1;
    }
    if (y1==0)
    {
        g[0][1]=g[1][0]=x1;
        g[0][2]=g[2][0]=n-x1;
    }
    if (x1==n)
    {
        g[0][2]=g[2][0]=y1;
        g[0][3]=g[3][0]=n-y1;
    }
    if (y1==n)
    {
        g[0][4]=g[4][0]=x1;
        g[0][3]=g[3][0]=n-x1;
    }
    if (x2==0)
    {
        g[5][1]=g[1][5]=y2;
        g[5][4]=g[4][5]=n-y2;
    }
    if (y2==0)
    {
        g[5][1]=g[1][5]=x2;
        g[5][2]=g[2][5]=n-x2;
    }
    if (x2==n)
    {
        g[5][2]=g[2][5]=y2;
        g[5][3]=g[3][5]=n-y2;
    }
    if (y2==n)
    {
        g[5][4]=g[4][5]=x2;
        g[5][3]=g[3][5]=n-x2;
    }
    if (x1==x2 && (x1==0 || x1==n))
    {
        g[0][5]=g[5][0]=abs(y1-y2);
    }
    if (y1==y2 && (y1==0 || y1==n))
    {
        g[0][5]=g[5][0]=abs(x1-x2);
    }
    for(k=0; k<maxn; k++)
        for(i=0; i<maxn; i++)
            for(j=0; j<maxn; j++)
                if (g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
    cout << g[0][5];
}