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
int sqrt_maxn=2154;
const int maxsqrt_n=205;
const int maxn=100005;
int a[maxn];
struct node
{
    int val;
    node * next;
    node * front;
};
node * front[maxsqrt_n];
node * rail[maxsqrt_n];
int dp[maxsqrt_n][maxn];
node * new_node()
{
    static node a[200005];
    static int top=0;
    return &a[top++];
}
void insert_node(int x,int y)
{
    node * t=new_node();
    t->val=y;
    t->next=front[x];
    if (front[x]!=0) front[x]->front=t;
    t->front=0;
    front[x]=t;
}
void trans_inside(int x,int y)
{
    register int j=x/sqrt_maxn;
    register int i;
    register node * t1=front[j];
    for (i=j*sqrt_maxn;i<=x;i++)
    {
        t1=t1->next;
    }
    register node * t2=t1;
    for (;i<=y;i++)
    {
        t2=t2->next;
    }
    t1->front->next=t2;
    t2->front->next=t2->next;
    t2->next->front=t2->front;
    t2->front=t1->front;
    t2->next=t1;
    t1->front=t2;
}
void trans(int x,int y)
{
    register int jx=x/sqrt_maxn;
    register int i;
    register node * t1=front[jx];
    for (i=jx*sqrt_maxn;i<=x;i++)
    {
        t1=t1->next;
    }
    int jy=y/sqrt_maxn;
    register node * t2=front[jy];
    for (i=jy*sqrt_maxn;i<=y;i++)
    {
        t2=t2->next;
    }
    t1->front->next=t2;
    t2->front->next=t2->next;
    t2->next->front=t2->front;
    t2->front=t1->front;
    t2->next=t1;
    t1->front=t2;
    dp[jx][t2->val]++;
    dp[jy][t2->val]--;
    for (i=jx;i<jy;i++)
    {
        t1=front[i+1]->next;
        t2=rail[i]->front;
        t1->front->next=t2;
        t2->front->next=t2->next;
        t2->next->front=t2->front;
        t2->front=t1->front;
        t2->next=t1;
        t1->front=t2;
        dp[i+1][t2->val]++;
        dp[i][t2->val]--;
    }
}
int calc_inside(int x,int y,int val)
{
    int j=x/sqrt_maxn;
    int i;
    node * t1=front[j];
    for (i=j*sqrt_maxn;i<=x;i++)
    {
        t1=t1->next;
    }
    register int ans=0;
    for (;i<=y;i++)
    {
        if (t1->val==val) ans++;
        t1=t1->next;
    }
    if (t1->val==val) ans++;
    return ans;
}
int calc(int x,int y,int val)
{
    int j=x/sqrt_maxn;
    int i;
    node * t1=front[j];
    for (i=j*sqrt_maxn;i<=x;i++)
    {
        t1=t1->next;
    }
    int ans=0;
    for (;t1->val!=-2;)
    {
        if (t1->val==val) ans++;
        t1=t1->next;
    }
    int jy=y/sqrt_maxn;
    for (i=j+1;i<jy;i++)
    {
        ans+=dp[i][val];
    }
    t1=front[jy];
    for (i=jy*sqrt_maxn;i<=y;i++)
    {
        t1=t1->next;
        if (t1->val==val) ans++;
    }
    return ans;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fprintf(stderr,"%d\n",clock());
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    memset(dp,0,sizeof(dp));
    for (i=0;i<n;i+=sqrt_maxn)
    {
        register int temp=i/sqrt_maxn;
        front[temp]=0;
        int j;
        insert_node(temp,-2);
        rail[temp]=front[temp];
        for (j=i+sqrt_maxn-1;j>=i;j--)
        {
            if (j>=n) continue;
            insert_node(temp,a[j]);
            dp[temp][a[j]]++;
        }
        insert_node(temp,-1);
    }
    int lastans=0;
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        int oper;
        scanf("%d",&oper);
        if (oper==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x=(x-1+lastans)%n;
            y=(y-1+lastans)%n;
            if (x>y) swap(x,y);
            if (x==y) continue;
            if (x/sqrt_maxn==y/sqrt_maxn)
            {
                trans_inside(x,y);
            }
            else
            {
                trans(x,y);
            }
        }
        else
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x=(x-1+lastans)%n;
            y=(y-1+lastans)%n;
            z=(z-1+lastans)%n;
            if (x>y) swap(x,y);
            if (x/sqrt_maxn==y/sqrt_maxn)
            {
                lastans=calc_inside(x,y,z);
            }
            else
            {
                lastans=calc(x,y,z);
            }
            printf("%d\n",lastans);
        }
    }
    fprintf(stderr,"%d\n",clock());
    return 0;
}