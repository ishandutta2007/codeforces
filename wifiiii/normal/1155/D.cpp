
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;

typedef long long ll;
ll a[300005],dp[3][300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=0;i<3;++i)
        for(int j=1;j<=n;++j)
        {
            if(i) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(i%2) dp[i][j] += x*a[j];
            else dp[i][j] += a[j];
        }
    ll ans = 0;
    for(int i=0;i<3;++i)
        for(int j=1;j<=n;++j)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;
}