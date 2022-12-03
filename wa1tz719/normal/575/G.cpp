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
int n;
int dist[100005];
int pre[100005];
int depth[100005];
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
void insert_edge(int x,int y,int z)
{
    edge * t=new_edge();
    t->y=y;
    t->weight=z;
    t->next=li[x];
    li[x]=t;
}
void dfs(int x)
{
    static int que[100005];
    int front=0,rail=1;
    memset(depth,-1,sizeof(depth));
    depth[x]=0;
    pre[x]=-2;
    que[0]=x;
    for (;front<rail;front++)
    {
        int now=que[front];
        edge * t;
        for (t=li[now];t!=0;t=t->next)
        {
            if ((t->weight==0)&&(depth[t->y]==-1))
            {
                depth[t->y]=depth[now]+1;
                pre[t->y]=now;
                que[rail++]=t->y;
            }
        }
    }
}
void bfs()
{
    static int que[100005];
    int front=0,rail=1;
    dist[0]=0;
    que[0]=0;
    for (;front<rail;front++)
    {
        int now=que[front];
        edge * t;
        for (t=li[now];t!=0;t=t->next)
        {
            if (dist[t->y]==-1)
            {
                dist[t->y]=dist[now]+1;
                que[rail++]=t->y;
            }
        }
    }
}
void bfs2()
{
    int i;
    static int que[100005];
    int front=0,rail=0;
    int min_x=n;
    for (i=0;i<n;i++)
    {
        if (pre[i]!=-1)
        {
            if (min_x>dist[i])
            {
                min_x=dist[i];
                rail=0;
            }
            if (min_x==dist[i])
            {
                que[rail++]=i;
            }
        }
    }
    if (pre[0]!=-1)
    {
        printf("0");
        return;
    }
    for (;;)
    {
        int last_rail=rail;
        int min_weight=10;
        for (;front<last_rail;front++)
        {
            int now=que[front];
            edge * t;
            for (t=li[now];t!=0;t=t->next)
            {
                if (dist[t->y]==dist[now]-1)
                {
                    if (t->weight<min_weight)
                    {
                        min_weight=t->weight;
                        rail=last_rail;
                        pre[t->y]=now;
                        depth[t->y]=depth[now]+1;
                    }
                    if (t->weight==min_weight)
                    {
                        que[rail++]=t->y;
                        if ((pre[t->y]==-1)||(depth[now]+1<depth[t->y]))
                        {
                            pre[t->y]=now;
                            depth[t->y]=depth[now]+1;
                        }
                    }
                }
            }
        }
        printf("%d",min_weight);
        if (pre[0]!=-1) break;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m;
    scanf("%d%d",&n,&m);
    int i;
    memset(dist,-1,sizeof(dist));
    for (i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        insert_edge(x,y,z);
        insert_edge(y,x,z);
    }
    memset(pre,-1,sizeof(pre));
    dfs(n-1);
    bfs();
    bfs2();
    printf("\n");
    int temp=0;
    int sum=1;
    for (;temp!=n-1;)
    {
        sum++;
        temp=pre[temp];
    }
    printf("%d\n",sum);
    temp=0;
    for (;temp!=n-1;)
    {
        printf("%d ",temp);
        temp=pre[temp];
    }
    printf("%d\n",temp);
    return 0;
}