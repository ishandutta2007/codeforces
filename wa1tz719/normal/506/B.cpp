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
struct edge
{
    int y;
    edge * next;
};
edge * li[100005];
edge * anti_li[100005];
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
void insert_edge(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
    t=new_edge();
    t->y=x;
    t->next=anti_li[y];
    anti_li[y]=t;
}
int ans=0;
bool visit[100005];
void bfs(int x)
{
    static int que[100005];
    int front=0,rail=1;
    que[0]=x;
    edge * t;
    ans++;
    visit[x]=true;
    for (;front<rail;front++)
    {
        int now=que[front];
        for (t=li[now];t!=0;t=t->next)
        {
            if (!visit[t->y])
            {
                visit[t->y]=true;
                ans++;
                que[rail++]=t->y;
            }
        }
        for (t=anti_li[now];t!=0;t=t->next)
        {
            if (!visit[t->y])
            {
                visit[t->y]=true;
                ans++;
                que[rail++]=t->y;
            }
        }
    }
}
int dfn[100005],low[100005];
int inque[100005];
void scc(int x)
{
    static int que[100005];
    static int top=0;
    static int num=0;
    dfn[x]=num++;
    low[x]=dfn[x];
    que[top++]=x;
    inque[x]=true;
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (dfn[t->y]==-1)
        {
            scc(t->y);
            if (visit[x]) return;
            low[x]=min(low[x],low[t->y]);
        }
        else if (inque[t->y])
        {
            low[x]=min(low[x],dfn[t->y]);
        }
    }
    if (low[x]==dfn[x])
    {
        int size=top;
        for (;;)
        {
            top--;
            inque[que[top]]=false;
            if (que[top]==x) break;
        }
        size=size-top;
        if (size>1) bfs(x);
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
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y);
    }
    memset(dfn,-1,sizeof(dfn));
    memset(low,-1,sizeof(low));
    memset(inque,false,sizeof(inque));
    for (i=0;i<n;i++)
    {
        if ((dfn[i]==-1)&&(!visit[i])) scc(i);
    }
    for (i=0;i<n;i++)
    {
        if (visit[i]) continue;
        bfs(i);
        ans--;
    }
    printf("%d\n",ans);
    return 0;
}