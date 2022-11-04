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
const int maxn=3005;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
double dp[maxn][maxn];

int main()
{
//    sync;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int j;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]<a[j])
                dp[i][j]=1;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        dp[x][y]=dp[y][x]=(dp[x][y]+dp[y][x])/2.0;
        for(j=1;j<=n;j++)
        {
            if(j==x||j==y)
                continue;
            dp[x][j]=dp[y][j]=(dp[x][j]+dp[y][j])/2.0;
            dp[j][x]=dp[j][y]=(dp[j][x]+dp[j][y])/2.0;
        }
    }
    double ans=0.0;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            ans+=dp[i][j];
        }
    }
    printf("%.8f\n",ans);
    return 0;
}