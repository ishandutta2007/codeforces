#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
const ll mod=1e9+7;
ll quickpow(ll k,ll n)
{
    if(n==0)
    {
        return 1;
    }
    ll ans=1;
    while(n)
    {
        if(n&1)
            ans=ans*k%mod;
        k=k*k%mod;
        n>>=1;
    }
    return ans;
}
ll n,k;
vector<vector<int>>g;
vector<bool>vis;
int dfs(int cur)
{
    vis[cur]=true;
    int cnt=1;
    for(auto &it:g[cur])
    {
        if(vis[it])
            continue;
        cnt+=dfs(it);
    }
    return cnt;
}
int main()
{
    cin>>n>>k;
    g.resize(n);
    vis.assign(n,false);
    for(int i=1,u,v,x;i<n;i++)
    {
        cin>>u>>v>>x;
        --u;--v;
        if(x==0)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    ll ans=quickpow(n,k);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            ans=(ans-quickpow(dfs(i),k)+mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}