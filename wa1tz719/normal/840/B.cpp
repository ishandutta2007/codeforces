#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[300005];
bool up[300005];
int num[300005];
struct edge
{
    int y;
    int id;
    edge * next;
};
edge * li[300005];
edge * new_edge()
{
    static edge a[600005];
    static int top=0;
    return &a[top++];
}
void inserts(int x,int y,int z)
{
    edge * t=new_edge();
    t->y=y;
    t->id=z;
    t->next=li[x];
    li[x]=t;
}
void insert_edge(int x,int y,int z)
{
    inserts(x,y,z);
    inserts(y,x,z);
}
int fa[300005];
bool vis[300005];
void dfs(int x)
{
    vis[x]=true;
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (vis[t->y]) continue;
        fa[t->y]=x;
        num[t->y]=t->id;
        dfs(t->y);
    }
}
void dfs2(int x)
{
    vis[x]=false;
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if ((fa[t->y]==x)&&(vis[t->y]))
        {
            dfs2(t->y);
            if (up[t->y]) up[x]^=1;
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int ans=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==-1) ans=-1;
        if (ans!=-1) ans^=a[i];
    }
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y,i+1);
    }
    if (ans==1)
    {
        puts("-1");
        return 0;
    }
    memset(fa,-1,sizeof(fa));
    dfs(0);
    ans=0;
    for (i=0;i<n;i++)
    {
        if (a[i]==1)
        {
            up[i]=1;
            ans^=1;
        }
    }
    if (ans==1)
    {
        for (i=0;i<n;i++)
        {
            if (a[i]==-1)
            {
                up[i]=1;
                break;
            }
        }
    }
    dfs2(0);
    int sum=0;
    for (i=1;i<n;i++)
    {
        if (up[i])
        {
            sum++;
        }
    }
    printf("%d\n",sum);
    for (i=1;i<n;i++)
    {
        if (up[i])
        {
            printf("%d\n",num[i]);
        }
    }
    return 0;
}