
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

const int mod = 1e9+7;
ll a[20],b[20];
ll dp[55][55][55][4];
ll dfs(int i,int j,int k,int m)
{
    if(dp[i][j][k][m]!=-1) return dp[i][j][k][m];
    if(i+j+k==0) return dp[i][j][k][m]=1;
    ll ret=0;
    if(m!=1&&j) ret += dfs(i,j-1,k,1)*j%mod;
    if(m!=2&&k) ret += dfs(i,j,k-1,2)*k%mod;
    if(m!=3&&i) ret += dfs(i-1,j,k,3)*i%mod;
    while(ret>=mod) ret-=mod;
    //cout<<i<<" "<<j<<" "<<k<<" "<<m<<" "<<ret<<endl;
    return dp[i][j][k][m]=ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;++i) cin>>a[i]>>b[i];
    ll ans = 0;
    for(int i=1;i<(1<<n);++i)
    {
        int sum = 0;
        for(int j=0;j<n;++j) if(i & (1<<j)) sum += a[j];
        if(sum != t) continue;
        int cnt[4] = {0};
        for(int j=0;j<n;++j) if(i & (1<<j)) cnt[b[j]]++;
        ans += dfs(cnt[1],cnt[2],cnt[3],0);
        while(ans>=mod) ans-=mod;
    }
    cout<<ans<<endl;
}