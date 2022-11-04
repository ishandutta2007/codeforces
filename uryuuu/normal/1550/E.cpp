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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
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
const ll Mod=1000000007;
//const ll Mod=998244353;


string s;
int a[maxn];
int dp[maxn];
int n,k;
int sz[maxn],ssz[maxn];

vector<int>g[maxn],h[20],p[20],pp[20];

int check(int len)
{
    for(int i=0;i<(1<<k);i++)
    {
        dp[i]=n+1;
    }
    dp[0]=0;
    int j,u,v,L,pre,pos,R;
    for(u=0;u<k;u++)
    {
        pp[u].clear();
        L=0;R=L+len-1;
        while(R<ssz[u])
        {
            if(p[u][R]-p[u][L]+1==len)
            {
                pp[u].push_back(p[u][L]);
            }
            L++;
            R++;
        }
    }
    
    for(int i=1;i<=k;i++)
    {
        for(int x:h[i])
        {
            for(j=0;j<sz[x];j++)
            {
                u=g[x][j];
                pre=(x-(1<<u));
                if(dp[pre]>=n+1)
                    continue;
                L=dp[pre]+1;
                pos=lower_bound(pp[u].begin(),pp[u].end(),L)-pp[u].begin();
                if(pos!=pp[u].size())
                {
                    dp[x]=min(dp[x],pp[u][pos]+len-1);
                }
            }
        }
    }
    if(dp[(1<<k)-1]<=n)
        return 1;
    return 0;
}


int main()
{
    sync;
    cin>>n>>k;
    cin>>s;
    int j,sum;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='?')
        {
            a[i]=-1;
            for(j=0;j<k;j++)
                p[j].push_back(i);
        }
        else
        {
            a[i]=int(s[i-1]-'a');
            p[a[i]].push_back(i);
        }
    }
    for(j=0;j<k;j++)
    {
        p[j].push_back(n+1);
        ssz[j]=p[j].size();
    }
    for(int i=1;i<(1<<k);i++)
    {
        sum=0;
        for(j=0;j<20;j++)
        {
            if(i&(1<<j))
            {
                g[i].push_back(j);
                sum++;
            }
        }
        sz[i]=g[i].size();
        h[sum].push_back(i);
    }
    int ans=0;
    int l=1,r=n/k,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            r=mid;
    }
    if(check(l))
        ans=max(ans,l);
    cout<<ans<<endl;
    
    return 0;
}