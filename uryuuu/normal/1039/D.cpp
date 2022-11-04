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
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;

vector<int>g[maxn],gg;
int ans[maxn];
int dp[maxn],fa[maxn],n;

void dfs(int u)
{
    for(int v:g[u])
    {
        if(v==fa[u])
            continue;
        fa[v]=u;
        dfs(v);
    }
    gg.push_back(u);
}

int solve(int k)
{
    int res=0;
    for(int i=1;i<=n;i++)
        dp[i]=1;
    for(int u:gg)
    {
        if(fa[u]&&dp[fa[u]]!=-1&&dp[u]!=-1)
        {
            if(dp[u]+dp[fa[u]]>=k)
            {
                res++;
                dp[fa[u]]=-1;
            }
            else
                dp[fa[u]]=max(dp[fa[u]],dp[u]+1);
        }
    }
    return res;
}

int main()
{
    sync;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int lmt=min(400,n);
    ans[1]=n;
    for(int i=2;i<=lmt;i++)
    {
        ans[i]=solve(i);
    }
    int l,r,mid,res;
    for(int i=lmt+1;i<=n;i++)
    {
        l=i;
        r=n;
        res=solve(l);
        while(l<r)
        {
            mid=(l+r+1)/2;
            if(solve(mid)==res)
                l=mid;
            else
                r=mid-1;
        }
        for(int j=i;j<=l;j++)
            ans[j]=res;
        i=l;
    }
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    return 0;
}