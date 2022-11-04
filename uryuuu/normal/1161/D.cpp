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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
//typedef pair<pii,int> piii;


ll pw[maxn];
char s[5005];
vector<pii>g[maxn];
int vis[maxn];

int check(int u)
{
    if(vis[u]==-1)
        vis[u]=0;
    for(auto f:g[u])
    {
        int v=f.first;
        int w=f.second;
        if(vis[v]==-1)
        {
            if(w==0)
                vis[v]=vis[u];
            else
                vis[v]=vis[u]^1;
            if(check(v)==0)
                return 0;
        }
        else
        {
            if(w==0&&vis[u]!=vis[v])
                return 0;
            if(w&&vis[u]==vis[v])
                return 0;
        }
    }
    return 1;
}

ll solve(int n,int m)
{
    for(int i=0;i<maxn;i++)
        g[i].clear();
    for(int i=1;i<=n/2;i++)
    {
        g[i].push_back(mkp(n-i+1,0));
        g[n-i+1].push_back(mkp(i,0));
    }
    for(int i=1;i<=m/2;i++)
    {
        g[n+n-m+i].push_back(mkp(n+n-i+1,0));
        g[n+n-i+1].push_back(mkp(n+n-m+i,0));
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?')
            continue;
        g[i].push_back(mkp(i+n,s[i]-'0'));
        g[i+n].push_back(mkp(i,s[i]-'0'));
    }
    int cnt=0;
    g[1].push_back(mkp(n+n+1,0));
    g[n+n+1].push_back(mkp(1,0));
    g[n+n-m+1].push_back(mkp(2*n+1,0));
    g[2*n+1].push_back(mkp(n+n-m+1,0));
    for(int i=1;i<=n-m;i++)
    {
        g[2*n+2].push_back(mkp(n+i,0));
        g[n+i].push_back(mkp(2*n+2,0));
    }
    g[2*n+2].push_back(mkp(2*n+1,1));
    g[2*n+1].push_back(mkp(2*n+2,1));
    
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=2*n+2;i++)
    {
        if(vis[i]!=-1)
            continue;
        if(check(i))
            cnt++;
        else
            return 0;
    }
    return pw[cnt-1];
}


int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    pw[0]=1ll;
    for(int i=1;i<=n;i++)
        pw[i]=2ll*pw[i-1]%Mod;
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans=(1ll*ans+solve(n,i))%Mod;
    }
    
    printf("%lld\n",(ans%Mod+Mod)%Mod);
    return 0;
}