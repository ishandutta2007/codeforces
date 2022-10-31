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
struct flight
{
    int day;
    int city;
    int cost;
    friend bool operator < (const flight &a,const flight &b)
    {
        return a.day<b.day;
    }
    void set_val(int d,int t,int c)
    {
        day=d;
        city=t;
        cost=c;
    }
};
flight froms[100005];
flight tos[100005];
long long ans1[1000005],ans2[1000005];
int tag[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i;
    int s1=0,s2=0;
    for (i=0;i<m;i++)
    {
        int d,s,t,c;
        scanf("%d%d%d%d",&d,&s,&t,&c);
        if (s==0)
        {
            tos[s2++].set_val(d,t,c);
        }
        else
        {
            froms[s1++].set_val(d,s,c);
        }
    }
    if (s1!=0) sort(froms,froms+s1);
    if (s2!=0) sort(tos,tos+s2);
    memset(tag,-1,sizeof(tag));
    long long now_sum=0;
    int now=0;
    int unlock=n;
    for (i=0;i<=1000000;i++)
    {
        if (now==s1)
        {
            if (unlock!=0)
            {
                ans1[i]=-1;
                continue;
            }
            ans1[i]=now_sum;
            continue;
        }
        if (froms[now].day==i)
        {
            int c=froms[now].cost;
            if (tag[froms[now].city]==-1)
            {
                tag[froms[now].city]=c;
                now_sum+=c;
                unlock--;
            }
            else if (tag[froms[now].city]>c)
            {
                now_sum-=tag[froms[now].city];
                tag[froms[now].city]=c;
                now_sum+=c;
            }
            i--;
            now++;
            continue;
        }
        if (unlock!=0)
        {
            ans1[i]=-1;
            continue;
        }
        ans1[i]=now_sum;
    }
    memset(tag,-1,sizeof(tag));
    now_sum=0;
    now=s2-1;
    unlock=n;
    for (i=1000000;i>=0;i--)
    {
        if (now<0)
        {
            if (unlock!=0)
            {
                ans2[i]=-1;
                continue;
            }
            ans2[i]=now_sum;
            continue;
        }
        if (tos[now].day==i)
        {
            int c=tos[now].cost;
            if (tag[tos[now].city]==-1)
            {
                tag[tos[now].city]=c;
                now_sum+=c;
                unlock--;
            }
            else if (tag[tos[now].city]>c)
            {
                now_sum-=tag[tos[now].city];
                tag[tos[now].city]=c;
                now_sum+=c;
            }
            i++;
            now--;
            continue;
        }
        if (unlock!=0)
        {
            ans2[i]=-1;
            continue;
        }
        ans2[i]=now_sum;
    }
    long long min_ans=-1;
    for (i=0;i+k+1<=1000000;i++)
    {
        if (ans1[i]==-1) continue;
        if (ans2[i+k+1]==-1) continue;
        if (min_ans==-1)
        {
            min_ans=ans1[i]+ans2[i+k+1];
        }
        else
        {
            min_ans=min(min_ans,ans1[i]+ans2[i+k+1]);
        }
    }
    cout<<min_ans<<endl;
    return 0;
}