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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
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
const int maxn=3005;
const ll Mod=1000000007;
//const ll Mod=998244353;


ll gcd(ll a,ll b)
{
    if(a==0)
        return 1ll;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}

ll L,R;


int mp[maxn],p[maxn],a[maxn],md=2520;
ll dp[22][maxn][60];
//LRx=f(x)(modm) 
ll dfs(int pos,int pre,int lcm,int lmt)
{
    if(pos<1)
    {
        return (pre%mp[lcm]==0);
    }
    if(lmt==0&&dp[pos][pre][lcm]!=-1)
        return dp[pos][pre][lcm];
    ll ans=0;
    int up=(lmt?a[pos]:9);
    int gd,LCM;
    for(int i=0;i<=up;i++)
    {
        LCM=mp[lcm];
        if(i>0)
        {
            gd=gcd(LCM,i);
            LCM=LCM*i/gd;
            LCM=p[LCM];
        }
        else
            LCM=lcm;
        ans+=dfs(pos-1,(pre*10+i)%md,LCM,i==up&&lmt);
    }
    if(lmt==0)
        dp[pos][pre][lcm]=ans;
    return ans;
}

ll solve(ll x)
{
    if(x==0)
        return 1ll;
    int len=0;
    while(x)
    {
        a[++len]=x%10ll;
        x=x/10ll;
    }
    
    return dfs(len,0,1,1);
}


int main()
{
    sync;
    int j;
    
    int gd;
    int m=0;
    for(int i=1;i<(1<<9);i++)
    {
        mp[++m]=1;
        for(j=1;j<=9;j++)
        {
            if(i&(1<<(j-1)))
            {
                gd=gcd(mp[m],j);
                mp[m]=mp[m]*j/gd;
            }
        }
    }
    sort(mp+1,mp+m+1);
    m=unique(mp+1,mp+m+1)-mp-1;
    for(int i=1;i<=m;i++)
    {
        p[mp[i]]=i;
    }
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    while(t--)
    {
        cin>>L>>R;
        cout<<solve(R)-solve(L-1)<<endl;
    }
    return 0;
}