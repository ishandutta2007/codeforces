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
const int maxn=2000005;
const ll Mod=1000000007;
//const ll Mod=998244353;

vector<int>g[maxn];
ll dp[maxn][7];
int f[maxn];
map<ll,int>mp;
int tot;
string s;
ll pm[maxn];

map<pll,int>vis;

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


int ck(char d)
{
    if(d=='w')
        return 1;
    if(d=='y')
        return 6;
    if(d=='g')
        return 2;
    if(d=='b')
        return 5;
    if(d=='r')
        return 3;
    return 4;
}

int dep(ll x)
{
    int ans=0;
    while(x)
    {
        x/=2ll;
        ans++;
    }
    return ans;
}

int k;
ll pre[maxn];

void dfs(int u)
{
//    cout<<u<<' '<<pm[u]<<endl;
    for(int v:g[u])
    {
        dfs(v);
    }
    ll h=k-dep(pm[u]);
    if(h==0)
    {
        if(f[u])
            dp[u][f[u]]=1ll;
        else
            for(int i=1;i<=6;i++)
                dp[u][i]=1ll;
        return;
    }
    
    h=pre[h];
    ll sum1,sum2;
    if(f[u])
    {
        if(g[u].size()==0)
        {
            dp[u][f[u]]=h*h%Mod;
        }
        else if(g[u].size()==1)
        {
            sum1=0;
            for(int i=1;i<=6;i++)
            {
                if(i!=f[u]&&i+f[u]!=7)
                    sum1+=dp[g[u][0]][i];
            }
            sum1=sum1%Mod;
            dp[u][f[u]]=h*sum1%Mod;
        }
        else
        {
            sum1=0;sum2=0;
            for(int i=1;i<=6;i++)
            {
                if(i!=f[u]&&i+f[u]!=7)
                {
                    sum1+=dp[g[u][0]][i];
                    sum2+=dp[g[u][1]][i];
                }
            }
            sum1=sum1%Mod;
            sum2=sum2%Mod;
            dp[u][f[u]]=sum2*sum1%Mod;
        }
        return;
    }
    
//    if(pm[u]==1)
//        cout<<g[u].size()<<endl;
////        cout<<"FK"<<' '<<u<<' '<<pm[u]<<' '<<sum1<<' '<<h<<endl;
    
    for(int c=1;c<=6;c++)
    {
        if(g[u].size()==0)
        {
            dp[u][c]=h*h%Mod;
        }
        else if(g[u].size()==1)
        {
            sum1=0;
            for(int i=1;i<=6;i++)
            {
                if(i!=c&&i+c!=7)
                    sum1+=dp[g[u][0]][i];
            }
            sum1=sum1%Mod;
            dp[u][c]=h*sum1%Mod;
        }
        else
        {
            sum1=0;sum2=0;
            for(int i=1;i<=6;i++)
            {
                if(i!=c&&i+c!=7)
                {
                    sum1+=dp[g[u][0]][i];
                    sum2+=dp[g[u][1]][i];
                }
            }
            sum1=sum1%Mod;
            sum2=sum2%Mod;
            dp[u][c]=sum2*sum1%Mod;
        }
    }
    
}

int main()
{
    sync;
    pre[1]=1ll;
    for(int i=2;i<=60;i++)
    {
        pre[i]=2ll*pre[i-1];
    }
    for(int i=2;i<=60;i++)
    {
        pre[i]=pre[i]+pre[i-1];
    }
    for(int i=1;i<=60;i++)
    {
        pre[i]=ksm(4ll,pre[i]);
//        cout<<i<<' '<<pre[i]<<endl;
    }
    pre[0]=1ll;
    int n;
    cin>>k>>n;
    ll x;
    tot=0;
    int now;
    for(int i=1;i<=n;i++)
    {
        s="";
        cin>>x>>s;
        if(mp[x]==0)
        {
            mp[x]=++tot;
        }
        pm[mp[x]]=x;
        f[mp[x]]=ck(s[0]);
        now=mp[x];
        while(x)
        {
            now=mp[x];
            x=x/2;
            if(mp[x]==0)
            {
                mp[x]=++tot;
            }
            pm[mp[x]]=x;
            if(vis[mkp(mp[x],now)]==0)
            {
                g[mp[x]].push_back(now);
                vis[mkp(mp[x],now)]=1;
            }
        }
    }
//    for(int i=1;i<=tot;i++)
//    {
//        cout<<i<<' '<<pm[i]<<endl;
//    }
    dfs(mp[1]);
//    cout<<dp[mp[2]][f[mp[2]]]<<endl;
    ll ans=0;
    for(int i=1;i<=6;i++)
    {
        ans=(ans+dp[mp[1]][i])%Mod;
    }
    cout<<(ans%Mod+Mod)%Mod<<endl;
    return 0;
}