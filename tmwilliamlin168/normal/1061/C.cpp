#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const int maxn=1e6+10;
ll a[maxn],dp[maxn];
vector<int>G[maxn];
void init()
{
    for(int i=1;i<maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
            G[j].push_back(i);
    }
}
int main()
{
    init();
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=G[a[i]].size()-1;j>=0;j--)
           dp[G[a[i]][j]]=(dp[G[a[i]][j]]+dp[G[a[i]][j]-1])%mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i];
    printf("%lld\n",ans%mod);
    return 0;
}