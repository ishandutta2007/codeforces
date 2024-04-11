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
struct node
{
    int type;
    int time;
    int x;
    int id;
    friend bool operator < (const node &a,const node &b)
    {
        if (a.x==b.x) return a.id<b.id;
        return a.x<b.x;
    }
    void read()
    {
        scanf("%d%d%d",&type,&time,&x);
    }
};
node a[100005];
int ans[100005];
int b[100005];
int n;
int sum[100005];
void add_val(int x,int y)
{
    x++;
    for (;;)
    {
        sum[x]+=y;
        x+=x&(-x);
        if (x>n) return;
    }
}
void clean_val(int x)
{
    x++;
    for (;;)
    {
        sum[x]=0;
        x+=x&(-x);
        if (x>n) return;
    }
}
int query_val(int x)
{
    x++;
    int ans=0;
    for (;;)
    {
        if (x==0) return ans;
        ans+=sum[x];
        x^=x&(-x);
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        a[i].read();
        a[i].id=i;
        b[i]=a[i].time;
    }
    sort(a,a+n);
    sort(b,b+n);
    for (i=0;i<n;i++)
    {
        a[i].time=lower_bound(b,b+n,a[i].time)-b;
    }
    a[n].x=-1;
    int last=0;
    for (i=0;i<n;i++)
    {
        if ((i==0)||(a[i].x!=a[i-1].x))
        {
            int j;
            for (j=last;j<i;j++)
            {
                clean_val(a[j].time);
            }
            last=i;
        }
        if (a[i].type==1)
        {
            add_val(a[i].time,1);
            ans[a[i].id]=-1;
        }
        if (a[i].type==2)
        {
            add_val(a[i].time,-1);
            ans[a[i].id]=-1;
        }
        if (a[i].type==3)
        {
            ans[a[i].id]=query_val(a[i].time);
        }
    }
    for (i=0;i<n;i++)
    {
        if (ans[i]==-1) continue;
        printf("%d\n",ans[i]);
    }
    return 0;
}