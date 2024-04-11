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

const int maxn=1005, inf=100000000;
char c[maxn][maxn];
int dp[maxn][2], v[maxn];


int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, x, y;
    cin >> n >> m >> x >> y;
    for(i=0; i<n; i++)
        scanf("%s", &c[i]);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            v[j+1]+=(c[i][j]=='.');
    for(j=1; j<=m; j++)
        v[j]+=v[j-1];
    for(i=1; i<=m; i++)
        dp[i][0]=dp[i][1]=inf;
    for(i=0; i<m; i++)
    {
        for(j=x; j<=y; j++)
            if (i+j<=m)
                dp[i+j][1]=min(dp[i+j][1], dp[i][0]+v[i+j]-v[i]);
        for(j=x; j<=y; j++)
            if (i+j<=m)
                dp[i+j][0]=min(dp[i+j][0], dp[i][1]+n*j-(v[i+j]-v[i]));         
    }
    cout << min(dp[m][0], dp[m][1]);
}