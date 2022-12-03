#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100005];
vector<int> v[105];
int ans[100005][105];
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
int dist[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int s,k;
    scanf("%d%d",&s,&k);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        v[a[i]].push_back(a[i]);
    }
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y);
    }
    for (i=1;i<=s;i++)
    {
        static int que[100005];
        int front=0,rail=0;
        int j;
        for (j=0;j<n;j++)
        {
            dist[j]=-1;
            if (a[j]==i)
            {
                que[rail++]=j;
                dist[j]=0;
            }
        }
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
        for (j=0;j<n;j++)
        {
            ans[j][i-1]=dist[j];
        }
    }
    for (i=0;i<n;i++)
    {
        sort(ans[i],ans[i]+s);
    }
    for (i=0;i<n;i++)
    {
        int j;
        int anses=0;
        for (j=0;j<k;j++)
        {
            anses+=ans[i][j];
        }
        printf("%d ",anses);
    }
    return 0;
}