#include<bits/stdc++.h>

using namespace std;

const int N=16;
const int M=1e4+100;
const int INF=1e9+100;

int a[N][M],g[N][N],h[N][N],dp[1<<N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    g[i][j]=INF;
                    for(int k=0;k<m;k++)
                        g[i][j]=min(g[i][j],abs(a[i][k]-a[j][k]));
                }
                h[i][j]=INF;
                for(int k=0;k<m-1;k++)
                    h[i][j]=min(h[i][j],abs(a[i][k]-a[j][k+1]));
            }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int mask=0;mask<(1<<n);mask++)
            for(int j=0;j<n;j++)
                dp[mask][j]=0;
        dp[1<<i][i]=INF;
        for(int mask=0;mask<(1<<n);mask++)
            for(int j=0;j<n;j++)
                if(mask&(1<<j))
                    for(int k=0;k<n;k++)
                        if(!(mask&(1<<k)))
                            dp[mask|(1<<k)][k]=max(dp[mask|(1<<k)][k],min(dp[mask][j],g[j][k]));
        for(int j=0;j<n;j++)
            ans=max(ans,min(dp[(1<<n)-1][j],h[j][i]));
    }
    cout<<ans;
}