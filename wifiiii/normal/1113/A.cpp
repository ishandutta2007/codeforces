#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;
typedef vector<int> vec;
typedef pair<ll,ll> pii;

int dp[205][205];
int main()
{
    int n,v;cin>>n>>v;
    for(int i=0;i<=201;++i)
        for(int j=0;j<=201;++j)
            dp[i][j] = -1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=v;++j)
            dp[i][j] = dp[i-1][j+1];
        dp[1][0] = 0;
        for(int j=1;j<=v;++j)
            if(dp[i][j]==-1) dp[i][j] = dp[i][j-1]+i;
            else dp[i][j] = min(dp[i][j], dp[i][j-1]+i);
    }
    int ans = 1e9;
    for(int i=0;i<=v;++i)
    {
        if(dp[n][i]>=0) ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}