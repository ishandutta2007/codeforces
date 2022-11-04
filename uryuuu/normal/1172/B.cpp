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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll s[maxn];

vector<int>g[maxn];

ll dfs(int u,int fa)
{
    ll sum=1ll;
    ll son=1;
    if(u==1)
    {
        son=0;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        son++;
        sum=1ll*sum*dfs(v,u)%Mod;
        sum=1ll*sum*son%Mod;
    }
    return 1ll*sum%Mod;
}

int main()
{
    sync;
    int n;
    cin>>n;
    s[1]=1ll;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]*i%Mod;
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    cout<<1ll*dfs(1,0)*n%Mod;
    
    return 0;
}