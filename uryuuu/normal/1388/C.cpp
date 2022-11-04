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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod=998244353;
  
vector<int>g[maxn];
int n,m;
ll p[maxn],h[maxn],a[maxn],b[maxn];

int flag;
void dfs(int u,int fa)
{
    int sz=g[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        dfs(v,u);
        a[u]+=a[v];
    }
    if(a[u]>m)
        flag=1;
        
}

void dfs2(int u,int fa)
{
    int sz=g[u].size();
    b[u]=0;
    for(int i=0;i<sz;i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        dfs2(v,u);
        b[u]+=b[v];
    }
    ll s=a[u]-h[u];
    if(s%2||s<0)
        flag=1;
    s/=2ll;
    if(b[u]+p[u]<s)
        flag=1;
    b[u]=s;
}


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            a[i]=p[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>h[i];
            g[i].clear();
        }
        a[0]=0;
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        flag=0;
        dfs(1,0);
        dfs2(1,0);
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    return 0;
}