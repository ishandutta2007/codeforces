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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=5005;
const ll Mod=1e9+7;

struct node
{
    int to,next;
}edg[maxn<<1];
int eid,head[maxn];
int fa[maxn],deep[maxn],top[maxn],siz[maxn],son[maxn],p[maxn],pos;     //p 
int b[maxn][maxn];
void init()
{
    pos=0;                                  //
    eid=0;                                  //
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)                  //
{
    edg[eid].to=v;
    edg[eid].next=head[u];
    head[u]=eid++;
    edg[eid].to=u;
    edg[eid].next=head[v];
    head[v]=eid++;
}
void dfs(int u,int pre,int d)              //
{
    fa[u]=pre;                             //
    siz[u]=1;
    deep[u]=d;
    son[u]=-1;
    for(int i=head[u];i!=-1;i=edg[i].next)
    {
        int v=edg[i].to;
        if(v==pre)
            continue;
        dfs(v,u,d+1);
        siz[u]+=siz[v];
        if(son[u]==-1||siz[son[u]]<siz[v])
            son[u]=v;
    }
}


void add(int u,int v,int w)
{
    while(u!=v)                            // 
    {
        if(deep[u]<deep[v])
        swap(u,v);
        b[u][fa[u]]=max(b[u][fa[u]],w);
        b[fa[u]][u]=b[u][fa[u]];
//        cout<<b[u][fa[u]]<<endl;
        u=fa[u];
    }
    return;
}

int query(int u,int v,int w)
{
    int ans=99999999;
    while(u!=v)                            // 
    {
        if(deep[u]<deep[v])
        swap(u,v);
        ans=min(ans,b[u][fa[u]]);
        u=fa[u];
    }
    return ans==w;
}


struct nod
{
    int u,v,w;
}t[maxn];

struct nd
{
    int u,v;
}c[maxn];

int main()
{
    int n,m;
    scanf("%d",&n);
    init();
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&c[i].u,&c[i].v);
        addedge(c[i].u,c[i].v);
    }
    dfs(1,1,1);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
    }
    for(int i=0;i<m;i++)
    {
        add(t[i].u,t[i].v,t[i].w);
    }
    for(int i=0;i<m;i++)
    {
        if(query(t[i].u,t[i].v,t[i].w)==0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        if(b[c[i].u][c[i].v]==0)
        {
            cout<<1<<' ';
        }
        else
            cout<<b[c[i].u][c[i].v]<<' ';
    }
    cout<<endl;
    return 0;
}