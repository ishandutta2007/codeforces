#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1000005];
int dp[1<<21];
int ans;
void update(int x)
{
    int now=0;
    for(int i=20;i>=0;--i)
    {
        if((1<<i)&x) continue;
        if(dp[now|(1<<i)]>=2) now|=1<<i;
    }
    ans=max(ans,x|now);
}
void dfs(int x,int k)
{
    if(dp[x]>=2) return;
    dp[x]++;
    for(;k<20;++k) if((1<<k)&x) dfs(x^(1<<k),k+1);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=n;i>=1;--i)
    {
        if(i<=n-2) update(a[i]);
        dfs(a[i],0);
    }
    cout<<ans<<endl;
}