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

const int maxn=105;
int x[maxn], y[maxn];
int d[maxn];
double dp[maxn][maxn];
int dis(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, n, k, lim, x0, y0, f=0;
    double p, r, q, pcur, eps=1e-12;
    cin >> n >> k >> lim >> x0 >> y0;
    for(i=0; i<n; i++)
        cin >> x[i] >> y[i];
    for(i=0; i<n; i++)
    {
        if ((d[i]=dis(x[i], y[i], x0, y0))==0)
            f++;
    }
    if (k<=f)
    {
        cout << "0.0000000";
        return 0;
    }
    sort(d, d+n);
    for(p=0., q=4000.; p+eps<q;)
    {
        r=(p+q)/2.;
        pcur=0.;
        for(i=0; i<=n; i++)
            for(j=0; j<=i; j++)
                dp[i][j]=0.;
        dp[0][0]=1.;
        for(i=0; i<n; i++)
            for(j=0; j<=i; j++)
            {
                if (d[i]<=r*r+eps)
                    dp[i+1][j+1]+=dp[i][j];
                else 
                {
                    pcur=exp(1.-d[i]/(r*r));
                    dp[i+1][j+1]+=dp[i][j]*pcur;
                    dp[i+1][j]+=dp[i][j]*(1.-pcur);
                }
            }
        pcur=0.;
        for(j=k; j<=n; j++)
            pcur+=dp[n][j];
        if (pcur*1000.<1000-lim)
            p=r;
        else 
            q=r;
    }
    printf("%.12lf", r);
}