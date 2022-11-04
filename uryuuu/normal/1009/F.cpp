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
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000010;
//const ll Mod=1000000007;
const ll Mod=998244353;

struct node
{
    int to,nxt;
}e[maxn<<1];
int head[maxn],tot;


inline void add(int u,int v)
{
    e[tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot++;
}


int siz[maxn],wson[maxn],dep[maxn],n;


void predfs(int u,int fa)
{
    siz[u]=1;
    dep[u]=dep[fa]+1;
    int mx=0;
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        predfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>mx)
        {
            mx=siz[v];
            wson[u]=v;
        }
    }
    return;
}


int cnt[maxn],ans[maxn],mx,id;

void md(int x,int val)
{
    cnt[x]+=val;
    if(mx<cnt[x])
    {
        mx=cnt[x];
        id=x;
    }
    if(mx==cnt[x]&&id>x)
    {
        mx=cnt[x];
        id=x;
    }
}

void add(int u,int fa,int val)
{
    md(dep[u],val);
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        add(v,u,val);
    }
}

void dfs(int u,int fa,int opt)
{
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||v==wson[u])
            continue;
        dfs(v,u,0);
    }
    
    if(wson[u])
        dfs(wson[u],u,1);
    md(dep[u],1);
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||v==wson[u])
            continue;
        add(v,u,1);
    }
    ans[u]=id;
    if(opt==0)
    {
        add(u,fa,-1);
        mx=0;
    }
}




int main()
{
    scanf("%d",&n);
    int u,v;
    tot=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dep[0]=0;
    predfs(1,0);
    dfs(1,0,1);
    
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]-dep[i]);
    }
    
    return 0;
}