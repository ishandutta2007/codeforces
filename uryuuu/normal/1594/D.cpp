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
const ll Mod=1000000007;
//const ll Mod=998244353;

int fa[maxn];
int sum[maxn];
string s;

int findx(int x)
{
    if(fa[x]==x)
        return x;
    int tmp=fa[x];
    fa[x]=findx(fa[x]);
    sum[x]=(sum[x]+sum[tmp])%2;
    return findx(fa[x]);
}
vector<int>g[maxn];

int main()
{
    sync;
   
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
            sum[i]=0;
            g[i].clear();
        }
        int u,v,fu,fv,c;
        int f=0;
        for(int i=1;i<=m;i++)
        {
            s="";
            cin>>u>>v>>s;
            fu=findx(u);
            fv=findx(v);
            if(s[0]=='i')
                c=1;
            else
                c=0;
            if(fu!=fv)
            {
                fa[fu]=fv;
                sum[fu]=(sum[v]-sum[u]+c)%2;
            }
            else
            {
                if(((sum[v]-sum[u])%2+2)%2!=c)
                    f=1;
            }
        }
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            g[findx(i)].push_back(i);
        }
        int ans=0;
        int sz;
        int j;
        int res;
        for(int i=1;i<=n;i++)
        {
            if(g[i].size()==0)
                continue;
            sz=g[i].size();
            u=g[i][0];
            res=1;
            for(j=1;j<sz;j++)
            {
                v=g[i][j];
                if((sum[v]-sum[u])%2==0)
                    res++;
            }
            ans+=max(res,sz-res);
        }
        cout<<ans<<endl;
    }
    return 0;
}