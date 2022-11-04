#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=200005;
ll powmod(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res;
}
 
ll a[200005],b[200005];
 
 
 
 
ll dp[maxn][2];
int main()
{
    sync;
    int n,c;
    cin>>n>>c;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        cin>>b[i];
    }
    dp[1][0]=0;
    dp[1][1]=c;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][1],dp[i-1][0])+a[i];
        dp[i][1]=min(dp[i-1][1]+b[i],dp[i-1][0]+b[i]+c);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<min(dp[i][0],dp[i][1])<<' ';
    }
    cout<<endl;
    return 0;
}