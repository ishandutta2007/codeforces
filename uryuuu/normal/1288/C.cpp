#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1e9+7;


ll f[2010],s[2010],dp[1010];
int main()
{
    sync;
    ll n,m;
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        s[i]=s[i-1]+dp[i];
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[j]=s[j];
        }
        for(int j=1;j<=n;j++)
        {
            s[j]=(s[j-1]+dp[j])%Mod;
        }
    }
    
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=(sum+(dp[i]*s[n-i+1]%Mod))%Mod;
    }
    cout<<(sum+Mod)%Mod;
    return 0;
}