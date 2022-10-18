#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5010,INF=1e9;

int a[N],dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        int val=INF;
        int k=min(n,a[i]);
        for(int j=0;j<=k;j++)
        {
            val=min(val+1,dp[i-1][j]);
            dp[i][j]=val+(j<a[i]);
        }
        for(int j=k+1;j<=n;j++)
            dp[i][k]=min(dp[i][k],dp[i-1][j]+(j<a[i]));
    }
    int ans=INF;
    for(int j=0;j<=min(n,a[n]);j++)
        ans=min(ans,dp[n][j]);
    cout<<ans;
}