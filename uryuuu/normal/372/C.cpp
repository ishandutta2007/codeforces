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

ll dp[2][maxn];
ll a[maxn],b[maxn],t[maxn],q[maxn];
int n,m,d;

int main()
{
    sync;
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i]>>t[i];
    
    int lst,now;
    for(int i=1;i<=m;i++)
    {
        now=i%2;
        lst=1-now;
        int L=1,R=0,k=1;
        for(int j=1;j<=n;j++)
        {
            for(;k<=min(1ll*n,j+d*(t[i]-t[i-1]));k++)
            {
                while(L<=R&&dp[lst][q[R]]<=dp[lst][k])
                    R--;
                q[++R]=k;
            }
            while(L<=R&&q[L]<max(1ll,j-d*(t[i]-t[i-1])))
                L++;
            dp[now][j]=dp[lst][q[L]]-abs(a[i]-j)+b[i];
        }
    }
    
    ll ans=-1e18;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[m%2][i]);
    }
    cout<<ans<<endl;
    return 0;
}