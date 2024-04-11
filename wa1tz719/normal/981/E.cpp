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
int modo[3];
int random_number()
{
    int i;
    int num=(1<<29);
    for (i=28;i>=0;i--)
    {
        if (rand()%2) num^=(1<<i);
    }
    return num;
}
bool check(int x)
{
    int i;
    for (i=2;i*i<=x;i++)
    {
        if (x%i==0) return false;
    }
    return true;
}
struct event
{
    int val;
    int time;
    friend bool operator < (const event &a,const event &b)
    {
        return a.time<b.time;
    }
};
int cnt=0;
event a[20005];
void insert_event(int time,int val)
{
    a[cnt].time=time;
    a[cnt].val=val;
    cnt++;
}
bool ans[10005];
int num[10005][3];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    srand(time(0));
    int n,q;
    scanf("%d%d",&n,&q);
    int i;
    for (i=0;i<3;i++)
    {
        int k=random_number();
        if (check(k))
        {
            modo[i]=k;
        }
        else
        {
            i--;
        }
    }
    for (i=0;i<q;i++)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        l--;
        insert_event(l,x);
        insert_event(r,-x);
    }
    sort(a,a+cnt);
    num[0][0]=1;
    num[0][1]=1;
    num[0][2]=1;
    int now=0;
    for (i=0;i<n;i++)
    {
        for (;;)
        {
            if ((now==cnt)||(a[now].time>i)) break;
            if (a[now].val<0)
            {
                //delete
                int j;
                for (j=0;j<=n+a[now].val;j++)
                {
                    int k;
                    for (k=0;k<3;k++)
                    {
                        num[j-a[now].val][k]-=num[j][k];
                        if (num[j-a[now].val][k]<0) num[j-a[now].val][k]+=modo[k];
                    }
                }
            }
            else
            {
                int j;
                for (j=n;j>=a[now].val;j--)
                {
                    int k;
                    for (k=0;k<3;k++)
                    {
                        num[j][k]+=num[j-a[now].val][k];
                        if (num[j][k]>=modo[k]) num[j][k]-=modo[k];
                    }
                }
            }
            now++;
        }
        int j;
        for (j=1;j<=n;j++)
        {
            if ((num[j][0]!=0)||(num[j][1]!=0)||(num[j][2]!=0))
            {
                ans[j]=true;
            }
        }
    }
    int ans_cnt=0;
    int j;
    for (j=1;j<=n;j++)
    {
        if (ans[j])
        {
            ans_cnt++;
        }
    }
    printf("%d\n",ans_cnt);
    for (j=1;j<=n;j++)
    {
        if (ans[j])
        {
            printf("%d ",j);
        }
    }
    return 0;
}