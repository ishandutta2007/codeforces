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
//const ll Mod=1000000007;
//const ll Mod=998244353;

int mp[30][30];
int n,k,t,cnt;
int vis[60];

void dfs(int pos,int sum,int mid)
{
    if(pos>n)
    {
        cnt++;
        return;
    }
    dfs(pos+1,sum,mid);
    for(int i=1;i<=n&&cnt<t;i++)
    {
        if(vis[i]==0&&mp[pos][i]&&sum+mp[pos][i]<=mid)
        {
            vis[i]=1;
            dfs(pos+1,sum+mp[pos][i],mid);
            vis[i]=0;
        }
    }
}

int main()
{
    sync;
    int u,v,w;
    cin>>n>>k>>t;
    for(int i=1;i<=k;i++)
    {
        cin>>u>>v>>w;
        mp[u][v]=w;
    }
    int l=0,r=n*1000,mid,ans=1e9;
    while(l<r)
    {
        mid=(l+r)/2;
        cnt=0;
        mm(vis);
        dfs(1,0,mid);
        if(cnt>=t)
        {
            r=mid;
            ans=min(mid,ans);
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}