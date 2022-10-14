#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll sum,fedya,x1,x2,a1,b1,k,j,x,y,n,m,rez1,rez2,rez,cnt,d,i,part[5005],dp[5005][5005],a[5005];
vector <ll> f,g;
string s;

int main()
{
    cin >> n >> m >> k;
    part[0] = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        part[i+1] = part[i] + a[i];
    }
    for (i = 0; i < n; i++)
        for (j = 0; j <= k; j++)
    {
        if (i+m <= n)
           dp[i+m][j+1] = max(dp[i+m][j+1],dp[i][j] + part[i+m] - part[i]);
        dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
    }
    cout << dp[n][k] << endl;
    return 0;
}