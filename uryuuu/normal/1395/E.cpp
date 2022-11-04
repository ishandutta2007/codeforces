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
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//const double pi=acos(-1);
const int maxn = 200010;
//const ll Mod=1000000007;
const int Mod = 998244353;

ll dp[10][10];
vector<pii>g[maxn];
ll sum=0;

bool cmp(pii a,pii b)
{
    return a.second<b.second;
}

int d[maxn];

ll ans=0;
int n,m,k;
int a[maxn];

void dfs(int s)
{
    if(s>k)
    {
        ll ss=0;
        for(int i=1;i<=k;i++)
        {
            ss=1ll*ss+1ll*dp[i][a[i]];
        }
//        for(int i=1;i<=k;i++)
//        {
//            cout<<a[i]<<' ';
//        }
//        cout<<ss<<endl;
        if(ss==sum)
            ans++;
        return;
    }
    for(int i=1;i<=s;i++)
    {
        a[s]=i;
        dfs(s+1);
    }
}

int main()
{
    sync;
    srand(unsigned(time(0)));
    srand(rand());
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=n;i++)
    {
        d[i]=int(rand());
        sum=1ll*sum+1ll*d[i];
//        cout<<d[i]<<' '<<sum<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(mkp(v,w));
    }
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end(),cmp);
//        for(int j=0,sz=g[i].size();j<sz;j++)
//            cout<<g[i][j].second<<' ';
//        cout<<endl;
        for(int j=0,sz=g[i].size();j<sz;j++)
        {
//            cout<<g[i][j].first<<' ';
            dp[sz][j+1]=1ll*dp[sz][j+1]+1ll*d[g[i][j].first];
        }
//        cout<<endl;
    }
    ans=0;
    dfs(1);
    cout<<ans<<endl;
    
    return 0;
}