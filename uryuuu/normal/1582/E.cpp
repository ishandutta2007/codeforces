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
const int maxn=100005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn];
int n;
ll dp[maxn][505];
int pw[505];
ll pre[maxn];

int solve(int up)
{
    int j;
    for(int i=0;i<=n;i++)
    {
        for(j=1;j<=up;j++)
        {
            dp[i][j]=-2e18;
        }
    }
    dp[0][0]=2e18;
    for(int i=1;i<=n;i++)
    {
        for(j=0;j<=up;j++)
        {
            dp[i][j]=dp[i-1][j];
        }
        for(j=1;j<=up;j++)
        {
            if(i-j<0)
                continue;
            if(pre[i]-pre[i-j]<dp[i-j][j-1])
            {
                dp[i][j]=max(dp[i][j],pre[i]-pre[i-j]);
//                cout<<i<<' '<<j<<' '<<pre[i]-pre[i-j]<<' '<<dp[i-j][j-1]<<' '<<endl;
            }
        }
    }
    int mx=0;
    for(j=1;j<=up;j++)
    {
        if(dp[n][j]>0)
            mx=j;
    }
    return mx;
}


int main()
{
    sync;
    pw[1]=1;
    for(int i=2;i<=500;i++)
    {
        pw[i]=pw[i-1]+i;
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pre[0]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int r;
        for(int i=1;i<=500;i++)
        {
            if(pw[i]<=n)
                r=i;
            else
                break;
        }
        reverse(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+a[i];
        }
        cout<<solve(r)<<endl;
    }
    return 0;
}