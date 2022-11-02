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
bool unok[100005];
struct edge
{
    int y;
    edge * next;
};
int degree[100005];
edge * li[100005];
edge * new_edge()
{
    static edge a[500005];
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
bool visit[100005];
const double eps=1e-10;
int used_degree[100005];
int n;
bool check(double x)
{
    static int que[100005];
    int front=0,rail=0;
    memcpy(used_degree,degree,sizeof(used_degree));
    memset(visit,false,sizeof(visit));
    int i;
    for (i=0;i<n;i++)
    {
        if (unok[i])
        {
            que[rail++]=i;
            visit[i]=true;
        }
    }
    for (;front<rail;front++)
    {
        edge * t;
        int now=que[front];
        for (t=li[now];t!=0;t=t->next)
        {
            if (!visit[t->y])
            {
                used_degree[t->y]--;
                if (used_degree[t->y]*1.0/degree[t->y]<x)
                {
                    que[rail++]=t->y;
                    visit[t->y]=true;
                }
            }
        }
    }
    for (i=0;i<n;i++)
    {
        if (!visit[i]) return true;
    }
    return false;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i;
    for (i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        unok[x]=true;
    }
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y);
        degree[x]++;
        degree[y]++;
    }
    double l=0,r=1;
    for (;r-l>eps;)
    {
        double mid=(l+r)/2;
        if (check(mid)) l=mid; else r=mid;
    }
    check(l);
    int sum=0;
    for (i=0;i<n;i++)
    {
        if (!visit[i])
        {
            sum++;
        }
    }
    printf("%d\n",sum);
    for (i=0;i<n;i++)
    {
        if (!visit[i])
        {
            printf("%d ",i+1);
        }
    }
    printf("\n");
    return 0;
}