#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=52,M=2e4+100,K=22;

int a[N][M],
    a_pref[N][M],
    dp[N][M],
    dp_pref[N][M],
    dp_suff[N][M];

int sum(int i,int l,int r)
{
    return a_pref[i][r]-a_pref[i][l-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a_pref[i][j]=a_pref[i][j-1]+a[i][j];
    m-=k-1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j-k>=1)
                dp[i][j]=max(dp[i][j],dp_pref[i-1][j-k]);
            if(j+k<=m)
                dp[i][j]=max(dp[i][j],dp_suff[i-1][j+k]);
            for(int p=max(j-k+1,1ll);p<=min(j+k-1,m);p++)
                dp[i][j]=max(dp[i][j],dp[i-1][p]-sum(i,max(j,p),min(j+k-1,p+k-1)));
            dp[i][j]+=sum(i,j,j+k-1)+sum(i+1,j,j+k-1);
            ans=max(ans,dp[i][j]);
//            cout<<i<<" "<<j<<" -> "<<dp[i][j]<<"\n";
        }
        for(int j=1;j<=m;j++)
            dp_pref[i][j]=max(dp_pref[i][j-1],dp[i][j]);
        for(int j=m;j>=1;j--)
            dp_suff[i][j]=max(dp_suff[i][j+1],dp[i][j]);
    }
    cout<<ans<<"\n";
}