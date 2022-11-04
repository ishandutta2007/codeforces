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
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=605;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll mp[maxn][maxn];
vector<int>g[maxn];
int dis[maxn][maxn];
int a[maxn],b[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    memset(dis,inf,sizeof(dis));
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        dis[v][u]=dis[u][v]=1;
    }
    int i,j,k;
    for(i=1;i<=n;i++)
        dis[i][i]=0;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    
    int len,cnt;
    ll w;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            mp[i][j]=1ll;
            len=dis[i][j];
            for(k=1;k<=n;k++)
            {
                a[k]=dis[k][i];
                b[k]=dis[k][j];
            }
            cnt=0;
            for(k=1;k<=n;k++)
            {
                if(a[k]+b[k]==len)
                    cnt++;
            }
            if(cnt>len+1)
            {
                mp[i][j]=0;
                continue;
            }
            for(k=1;k<=n;k++)
            {
                if(a[k]+b[k]<=len)
                {
                    continue;
                }
                w=0ll;
                for(int v:g[k])
                {
                    if(a[v]+1==a[k]&&b[v]+1==b[k])
                        w++;
                }
                mp[i][j]=1ll*w*mp[i][j]%Mod;
            }
        }
    }
    
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<mp[i][j]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}