#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e18;

int dp[N][3];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        string s;
        cin>>n>>a>>b>>s;
        s="_"+s;
        dp[0][1]=b;
        dp[0][2]=INF;
        for(int i=1;i<=n;i++)
            if(s[i]=='0')
                dp[i][1]=min(dp[i-1][1]+a+b,dp[i-1][2]+2*a+b),
                dp[i][2]=min(dp[i-1][2]+a+2*b,dp[i-1][1]+2*a+2*b);
            else
                dp[i][1]=INF,
                dp[i][2]=dp[i-1][2]+a+2*b;
        cout<<dp[n][1]<<"\n";
    }
}