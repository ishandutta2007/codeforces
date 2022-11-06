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

const int nmax=1005;
char g[nmax][nmax];
vector<int> sorted;
double dp[nmax], p[nmax];
char col[nmax];
int n;
long long x[nmax], y[nmax], t[nmax];

void dfs(int s)
{
    int i;
    col[s]=1;
    for(i=1; i<=n; i++)
        if (g[s][i] && !col[i])
            dfs(i);
    sorted.push_back(s);
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j;
    double mx;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> x[i] >> y[i] >> t[i] >> p[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if (i==j) 
                continue;
            if (t[i]>=t[j]) 
                continue;
            if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=(t[i]-t[j])*(t[i]-t[j]))
                g[i][j]=1;
        }
    for(i=1; i<=n; i++)
        g[0][i]=1;
    dfs(0);
    reverse(sorted.begin(), sorted.end());
    for(i=1; i<=n; i++)
    {
        mx=0.;
        for(j=0; j<i; j++)
            if (g[sorted[j]][sorted[i]] && dp[sorted[j]]>mx)
                mx=dp[sorted[j]];
        dp[sorted[i]]=mx+p[sorted[i]];
    }
    mx=0.;
    for(i=1; i<=n; i++)
        if (dp[i]>mx)
            mx=dp[i];
    printf("%.12lf", mx);

}