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
ll sum,x1,x2,a1,b1,k,j,x,y,n,m,rez1,rez2,rez,cnt,d,i,b,dp[2005][2005],a[600000];
vector <ll> f,g;
string s;

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (i = 0; i < n; i++)
    {
        ll opened = m - a[i];
        if (opened > 0)
        {
        dp[i+1][opened] = (dp[i][opened] + dp[i][opened-1])%tr;
        dp[i+1][opened-1] = (dp[i][opened]*opened+dp[i][opened-1]*opened)%tr;
        }
        else
        {
        dp[i+1][opened] = dp[i][opened];
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}