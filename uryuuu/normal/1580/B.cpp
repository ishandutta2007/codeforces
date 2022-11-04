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
const int maxn=105;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll m,mod,dp[maxn][maxn][maxn],vis[maxn][maxn][maxn],c[maxn][maxn];

ll dfs(int i,int j,int k)
{
    if(i+1<2*k||i<k)
        return 0;
    if(j>m&&k>0)
        return 0;
    if(j==m&&k>1)
        return 0;
    if(i==0)
        return (k==0);
    if(vis[i][j][k])
        return dp[i][j][k];
    vis[i][j][k]=1;
    int lim=k;
    if(j==m)
        lim--;
    int a,b;
    for(a=0;a<i;a++)
    {
        for(b=0;b<=lim;b++)
        {
            dp[i][j][k]=(dp[i][j][k]+1ll*c[i-1][a]*dfs(a,j+1,b)%mod*dfs(i-1-a,j+1,lim-b)%mod)%mod;
        }
    }
    return dp[i][j][k];
}


int main()
{
    sync;
    int n,k;
    cin>>n>>m>>k>>mod;
    c[0][0]=1ll;
    for(int i=1;i<=n;i++)
    {
        c[i][0]=c[i][i]=1ll;
        for(int j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    cout<<(dfs(n,1,k)%mod+mod)%mod;
    return 0;
}