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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=5005;
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

int col[maxn];

struct node
{
    int x,y;
}a[maxn];

int dis[maxn][maxn];

int gt(int u,int v)
{
    return abs(a[u].x-a[v].x)+abs(a[u].y-a[v].y);
}

int num;
int n;

int dfs(int u,int mid)
{
    for(int i=1;i<=n;i++)
    {
        if(dis[u][i]<=mid||u==i)
            continue;
        if(col[i]==0)
        {
            col[i]=3-col[u];
            if(dfs(i,mid)==0)
                return 0;
        }
        else
        {
            if(col[i]==col[u])
                return 0;
        }
    }
    return 1;
}

int check(int mid)
{
    mm(col);
    num=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==0)
        {
            col[i]=2;
            num++;
            if(dfs(i,mid)==0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=gt(i,j);
        }
    }
    int l=0,r=1e4;
    int mid,ans=1e6;
    while(l<r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            ans=min(ans,mid);
            r=mid;
        }
        else
            l=mid+1;
    }
    check(ans);
    cout<<ans<<endl;
    cout<<ksm(2ll,num)<<endl;
    
    return 0;
}