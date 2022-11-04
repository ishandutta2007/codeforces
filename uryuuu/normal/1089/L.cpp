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
const int maxn=200005;
const ll Mod=1000000007;
//const ll Mod=998244353;


vector<int>g[maxn];
int a[maxn];
ll b[maxn];
ll lv[maxn];
int vis[maxn];

bool cmp(int u,int v)
{
    return b[u]>b[v];
}

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        g[a[i]].push_back(i);
        vis[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int sz;
    ll ans=0;
    int j;
    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        sort(g[i].begin(),g[i].end(),cmp);
        sz=g[i].size();
        if(sz>1)
        {
            for(j=1;j<sz;j++)
            {
                lv[++cnt]=b[g[i][j]];
            }
        }
    }
    sort(lv+1,lv+cnt+1);
    int s=0;
    for(int i=1;i<=k;i++)
    {
        if(vis[i]==0)
            s++;
    }
    for(int i=1;i<=s;i++)
    {
        ans+=lv[i];
    }
    cout<<ans<<endl;
    return 0;
}