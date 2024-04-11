
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

char g[1005][1005];
int dp1[1005][1005],dp2[1005][1005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    forii forjj cin>>g[i][j];
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dp1[i][j]=dp2[i][j]=1;
            if(g[i][j]==g[i-1][j]) dp1[i][j]=dp1[i-1][j]+1;
            if(g[i][j]==g[i][j-1]) dp2[i][j]=dp2[i][j-1]+1;
        }
    }
    for(int len=1;len<=n/3+1;++len)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(i-2*len>=0 && dp1[i][j]==len && dp1[i-len][j]==len && dp1[i-len-len][j]>=len)
                {
                    int cnt=1e9;
                    for(int k=0;k<len;++k)
                    {
                        cnt=min(cnt,dp2[i-k][j]);
                        cnt=min(cnt,dp2[i-len-k][j]);
                        cnt=min(cnt,dp2[i-2*len-k][j]);
                    }
                    ans+=cnt;
                }
            }
        }
    }
    cout<<ans<<endl;
}