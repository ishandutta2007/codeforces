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

const long long inf=1000000000000000;
const int maxn=3005;
long long dp[maxn][maxn];
pair<long long, long long> vv[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j;
    long long mn;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> vv[i].first >> vv[i].second;
    }
    sort(vv, vv+n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            dp[i][j]=inf;
    dp[0][0]=vv[0].second;
    for(i=0; i<n-1; i++)
        for(j=0; j<=i; j++)
        {
            if (dp[i][i]==inf)
                continue;
            dp[i+1][j]=min(dp[i+1][j], dp[i][j]+vv[i+1].first-vv[j].first);
            dp[i+1][i+1]=min(dp[i+1][i+1], dp[i][j]+vv[i+1].second);
        }
    mn=inf;
    for(i=0; i<n; i++)
        mn=min(mn, dp[n-1][i]);
    cout << mn;
}