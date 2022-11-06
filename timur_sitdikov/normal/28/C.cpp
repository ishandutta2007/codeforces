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

const int nmax = 105;
double p[nmax][nmax][nmax];
int a[nmax];

double bernulli(int m, int n, double p)
{
    int m1=min(m, n-m), i;
    double ans=1.;
    for(i=1; i<=m; i++)
        ans=ans*(n+1-i)*p/i;
    /*for(i=1; i<=m; i++)
        ans*=p;*/
    for(; i<=n; i++)
        ans*=(1.-p);
    return ans;
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, k, k1, k2, n, m;
    double tmp_bern, ans, ctrl;
    cin >> n >> m;
    for(i=1; i<=m; i++)
        cin >> a[i];
    p[n][m][0]=1.;
    for(i=n; i>0; i--)
        for(j=m; j>0; j--)
            for(k=0; k<=n; k++)
                for(k1=0; k1<=i; k1++)
                    p[i-k1][j-1][max(k, (k1+a[j]-1)/a[j])]+=p[i][j][k]*bernulli(k1, i, 1./j);
    ans=ctrl=0.;
    for(k=1; k<=n; k++)
        for(j=0; j<m; j++)
        {
            ans+=p[0][j][k]*k;
            ctrl+=p[0][j][k];
        }
    printf("%.12lf", ans);
}