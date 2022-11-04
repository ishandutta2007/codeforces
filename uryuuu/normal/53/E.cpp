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
const int maxn=3005;
const ll Mod=1000000007;
//const ll Mod=998244353;

vector<int>g[maxn];
ll dp[maxn][maxn],cnt[maxn];

int main()
{
    sync;
    int j;
    for(int i=1;i<maxn;i++)
    {
        for(j=0;j<12;j++)
        {
            if(i&(1<<j))
                cnt[i]++;
        }
    }
    int n,m,k;
    cin>>n>>m>>k;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<(1<<n);i<<=1)
    {
        dp[i][i]=1;
    }
    int now;
    for(int i=1;i<(1<<n);i++)
    {
        for(j=i;j>=1;j=((j-1)&i))
        {
            if(dp[i][j])
            {
                for(u=0;u<n;u++)
                {
                    if(i&(1<<u))
                    {
                        for(int v:g[u])
                        {
                            if(!(i&(1<<v)))
                            {
                                if(cnt[i]==1)
                                    now=i|(1<<v);
                                else
                                {
                                    now=j|(1<<v);
                                    if(j&(1<<u))
                                        now-=(1<<u);
                                }
                                if((now>>(v+1))==0)
                                    dp[i|(1<<v)][now]+=dp[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans=0ll;
    for(int i=0;i<(1<<n);i++)
    {
        if(cnt[i]==k)
            ans+=dp[(1<<n)-1][i];
    }
    cout<<ans<<endl;
    return 0;
}