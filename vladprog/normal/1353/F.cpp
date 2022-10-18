#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110,INF=1e18;

int a[N][N],dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j],
                a[i][j]-=i+j;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=INF;
        dp[1][0]=dp[0][1]=0;
        int ans=INF;
        for(int i0=1;i0<=n;i0++)
            for(int j0=1;j0<=m;j0++)
            {
                int val=a[i0][j0];
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                        dp[i][j]=(a[i][j]>=val?
                                  a[i][j]-val+min(dp[i-1][j],dp[i][j-1]):
                                  INF);
                ans=min(ans,dp[n][m]);
            }
        cout<<ans<<"\n";
    }
}