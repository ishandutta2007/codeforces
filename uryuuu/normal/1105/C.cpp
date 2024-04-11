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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll ksm(ll x,ll y)
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
    return res%Mod;
}

ll dp[maxn][3];

int main()
{
    sync;
    int n,l,r;
    cin>>n>>l>>r;
    int dn0=l/3*3;
    if(dn0<l)
        dn0+=3;
    int up0=r/3*3;
    int len0=max(0,(up0-dn0)/3+1);
    
    int dn1=l/3*3-2;
    while(dn1<l)
        dn1+=3;
    int up1=r/3*3-2;
    while(up1+3<=r)
        up1+=3;
    int len1=max(0,(up1-dn1)/3+1);
    
    int dn2=l/3*3-1;
    while(dn2<l)
        dn2+=3;
    int up2=r/3*3-1;
    while(up2+3<=r)
        up2+=3;
    int len2=max(0,(up2-dn2)/3+1);
    
    dp[0][0]=1ll;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][1]*len2+dp[i-1][2]*len1+dp[i-1][0]*len0)%Mod;
        dp[i][1]=(dp[i-1][2]*len2+dp[i-1][0]*len1+dp[i-1][1]*len0)%Mod;
        dp[i][2]=(dp[i-1][0]*len2+dp[i-1][1]*len1+dp[i-1][2]*len0)%Mod;
    }
    cout<<(dp[n][0]%Mod+Mod)%Mod;
    
    return 0;
}