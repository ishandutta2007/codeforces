#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5010;

int dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    a="_"+a,b="_"+b;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
            dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]-2);
            ans=max(ans,dp[i][j]);
        }
    cout<<ans;
}