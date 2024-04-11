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
//#include<unordered_map>
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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int n,m,k;

vector<int>g[maxn];
int st[maxn],cnt,dep[maxn];
int ans[maxn],f[maxn],cc;

void dfs(int u,int fa)
{
    st[++cnt]=u;
    dep[u]=cnt;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        if(dep[v]==0)
            dfs(v,u);
        else
        {
            if(dep[u]-dep[v]<=k-1&&dep[u]-dep[v]>=2)
            {
                cout<<2<<endl;
                cout<<dep[u]-dep[v]+1<<endl;
                for(int i=dep[v];i<=cnt;i++)
                {
                    cout<<st[i]<<' ';
                }
                cout<<endl;
                exit(0);
            }
        }
    }
    cnt--;
    if(f[u]==0)
    {
        ans[cc++]=u;
        for(int i=0;i<g[u].size();i++)
        {
            f[g[u][i]]=1;
        }
    }
}



int main()
{
    sync;
    cin>>n>>m>>k;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt=0;
    dfs(1,0);
    cout<<1<<endl;
    for(int i=0;i<(k+1)/2;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}