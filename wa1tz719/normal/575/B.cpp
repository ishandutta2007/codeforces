#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<math.h>
#include<string>
#include<time.h>
#include<bitset>
#include<vector>
#include<memory>
#include<utility>
#include<stdio.h>
#include<sstream>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct edge
{
    int y;
    int weight;
    edge * next;
};
edge * li[100005];
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
void inserts(int x,int y,int z)
{
    edge * t=new_edge();
    t->y=y;
    t->weight=z;
    t->next=li[x];
    li[x]=t;
}
void insert_edge(int x,int y,int z)
{
    inserts(x,y,0);
    inserts(y,x,z);
}
int l0,r0;
int val[2][1<<20];
int dfn[100005];
int depth[100005];
int size[100005];
int father[100005];
int up[100005];
int unok[100005][2];
edge * max_weight[100005];
void dfs1(int x)
{
    edge * t;
    size[x]=1;
    for (t=li[x];t!=0;t=t->next)
    {
        if (t->y!=father[x])
        {
            father[t->y]=x;
            depth[t->y]=depth[x]+1;
            dfs1(t->y);
            size[x]+=size[t->y];
            unok[t->y][1]=t->weight;
        }
        else
        {
            unok[x][0]=t->weight;
        }
    }
    int max_now=0;
    for (t=li[x];t!=0;t=t->next)
    {
        if (t->y!=father[x])
        {
            if (size[t->y]>max_now)
            {
                max_now=size[t->y];
                max_weight[x]=t;
            }
        }
    }
}
void dfs2(int x)
{
    static int top=0;
    dfn[x]=top++;
    if (max_weight[x]!=0)
    {
        up[max_weight[x]->y]=up[x];
        dfs2(max_weight[x]->y);
    }
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (t->y==father[x]) continue;
        if (t==max_weight[x]) continue;
        up[t->y]=t->y;
        dfs2(t->y);
    }
}
int lca(int x,int y)
{
    for (;;)
    {
        if (depth[up[x]]<depth[up[y]]) swap(x,y);
        if (up[x]==up[y])
        {
            if (depth[x]<depth[y]) swap(x,y);
            return y;
        }
        x=up[x];
        x=father[x];
    }
}
const int modo=1000000007;
int power2[1000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    fprintf(stderr,"%d\n",clock());
    #endif
    int n;
    scanf("%d",&n);
    int i;
    power2[0]=0;
    for (i=1;i<=1000001;i++)
    {
        power2[i]=(power2[i-1]*2+1)%modo;
    }
    for (i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--;
        y--;
        insert_edge(x,y,z);
    }
    memset(father,-1,sizeof(father));
    dfs1(0);
    dfs2(0);
    int m;
    scanf("%d",&m);
    int last;
    last=0;
    for (i=0;i<m;i++)
    {
        int now;
        scanf("%d",&now);
        now--;
        int x=last,y=now;
        last=now;
        int z=lca(x,y);
        int k=0;
        for (;;)
        {
            if (up[x]==up[z])
            {
                l0=dfn[z];
                r0=dfn[x];
                val[k][r0]++;
                val[k][l0]--;
                break;
            }
            else
            {
                l0=dfn[up[x]];
                r0=dfn[x];
                val[k][r0]++;
                val[k][l0-1]--;
            }
            x=father[up[x]];
        }
        k=1;
        for (;;)
        {
            if (up[y]==up[z])
            {
                l0=dfn[z];
                r0=dfn[y];
                val[k][r0]++;
                val[k][l0]--;
                break;
            }
            else
            {
                l0=dfn[up[y]];
                r0=dfn[y];
                val[k][r0]++;
                val[k][l0-1]--;
            }
            y=father[up[y]];
        }
    }
    int sum=0;
    for (i=n-1;i>=0;i--)
    {
        val[0][i]+=val[0][i+1];
        val[1][i]+=val[1][i+1];
    }
    for (i=1;i<n;i++)
    {
        if (unok[i][0]) sum+=power2[val[0][dfn[i]]];
        if (sum>=modo) sum-=modo;
        if (unok[i][1]) sum+=power2[val[1][dfn[i]]];
        if (sum>=modo) sum-=modo;
    }
    printf("%d\n",sum);
    #ifdef absi2011
    fprintf(stderr,"%d\n",clock());
    #endif
    return 0;
}