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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=400050;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int a[maxn],b[maxn];
ll c[30],v[30][30];
vector<int>g[maxn];
ll dp[1<<22];

int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int cnt=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+cnt+1,a[i])-b-1;
    }
    int R=1<<cnt;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            v[a[i]][j]+=1ll*c[j];
        }
        c[a[i]]++;
    }
    for(int i=0;i<R;i++)
    {
        g[__builtin_popcount(i)].push_back(i);
    }
    memset(dp,inf,sizeof(dp));
    dp[0]=0;
    
    for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            for(int k=0;k<g[i].size();k++)
            {
                int u=g[i][k];
                if((u&(1<<j))==0)
                    continue;
                u-=1<<j;
                ll ans=0;
                for(int d=0;d<cnt;d++)
                {
                    if(u&(1<<d))
                        ans+=1ll*v[j][d];
                }
                dp[u+(1<<j)]=min(dp[u+(1<<j)],dp[u]+ans);
            }
        }
    }
    cout<<dp[R-1]<<endl;
    
    return 0;
}