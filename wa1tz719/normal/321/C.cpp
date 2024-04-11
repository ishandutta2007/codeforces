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
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char ans[100005];
int size[100005];
int visit[100005];
int best_ans;
int best_val;
struct edge
{
    int y;
    edge * next;
};
edge * li[100005];
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
void inserts(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
void insert_edge(int x,int y)
{
    inserts(x,y);
    inserts(y,x);
}
void dfs1(int x)
{
    size[x]=1;
    visit[x]=true;
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (ans[t->y]!='\0') continue;
        if (visit[t->y]) continue;
        dfs1(t->y);
        size[x]+=size[t->y];
    }
}
void dfs2(int x,int sumsize)
{
    edge * t;
    visit[x]=true;
    int max_ans=sumsize-size[x];
    for (t=li[x];t!=0;t=t->next)
    {
        if (ans[t->y]!='\0') continue;
        if (visit[t->y]) continue;
        dfs2(t->y,sumsize);
        max_ans=max(max_ans,size[t->y]);
    }
    if (max_ans<best_val)
    {
        best_val=max_ans;
        best_ans=x;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y);
    }
    memset(ans,'\0',sizeof(ans));
    for (i=0;i<26;i++)
    {
        memset(size,0,sizeof(size));
        memset(visit,0,sizeof(visit));
        int j;
        for (j=0;j<n;j++)
        {
            if (ans[j]!='\0') continue;
            if (visit[j]) continue;
            dfs1(j);
        }
        memset(visit,0,sizeof(visit));
        for (j=0;j<n;j++)
        {
            if (ans[j]!='\0') continue;
            if (visit[j]) continue;
            best_ans=-1;
            best_val=10000000;
            dfs2(j,size[j]);
            ans[best_ans]=i+'A';
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%c ",ans[i]);
    }
    printf("\n");
    return 0;
}