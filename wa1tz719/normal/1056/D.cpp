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
struct edge
{
    int y;
    edge * next;
};
edge * new_edge()
{
    static edge a[200005];
    static int top=0;
    return &a[top++];
}
edge * li[100005];
void insert_edge(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
int size[100005];
int cnt[100005];
void dfs(int x)
{
    edge * t;
    if (li[x]==0)
    {
        size[x]=1;
    }
    else
    {
        size[x]=0;
    }
    for (t=li[x];t!=0;t=t->next)
    {
        dfs(t->y);
        size[x]+=size[t->y];
    }
    cnt[size[x]]++;
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
    for (i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        insert_edge(x,i);
    }
    dfs(0);
    int sum=0,val=0;
    for (i=1;i<=n;i++)
    {
        for (;;)
        {
            if (val>=i)
            {
                break;
            }
            sum++;
            val+=cnt[sum];
        }
        printf("%d ",sum);
    }
    return 0;
}