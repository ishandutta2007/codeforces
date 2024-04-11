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
struct edge
{
    int val;
    int sum;
    bool vis;
    edge * next;
    edge * last;
};
edge * new_edge()
{
    static edge a[1000005];
    static int top=0;
    return &a[top++];
}
edge * b[100005];
edge * c[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=new_edge();
        b[i]->val=a[i];
        b[i]->sum=1;
        b[i]->vis=false;
    }
    for (i=1;i<n;i++)
    {
        b[i]->last=b[i-1];
    }
    b[0]->last=b[n-1];
    for (i=0;i<n-1;i++)
    {
        b[i]->next=b[i+1];
    }
    b[n-1]->next=b[0];
    edge * t=b[0];
    for (;;)
    {
        if (t->next==t) break;
        if (t->next->val==t->val)
        {
            t->sum+=t->next->sum;
            t->next->next->last=t;
            t->next=t->next->next;
            continue;
        }
        t->sum%=k;
        if (t->sum==0)
        {
            t->next->last=t->last;
            t->last->next=t->next;
            t=t->last;
        }
        else
        {
            t->vis=true;
            t=t->next;
            if (t->vis) break;
        }
    }
    //t is the head!
    long long ans=0;
    int not_cnt=-1;
    if (t->sum==0)
    {
        //Nothing happened?
        m=1;
    }
    else
    {
        if (t->next==t)
        {
            ans=(long long)t->sum*m%k-t->sum;
            t->sum=(long long)t->sum*m%k;
            if (t->sum==0)
            {
                printf("0\n");
                return 0;
            }
            //not_cnt=t->val;
        }
        else
        {
            int cnt=0;
            for (;;)
            {
                cnt+=t->sum;
                t->vis=false;
                t=t->next;
                if (!t->vis) break;
            }
            ans+=(long long)cnt*(m-1);
        }
    }
    {
        edge * null=new_edge();
        null->last=null;
        null->next=null;
        null->val=-1;
        null->sum=0;
        for (i=0;i<n;i++)
        {
            c[i]=new_edge();
            c[i]->val=a[i];
            c[i]->sum=1;
            if (a[i]!=not_cnt) ans++;
        }
        for (i=0;i<n;i++)
        {
            c[i]->next=c[i+1];
            if (i!=0) c[i]->last=c[i-1];
        }
        c[n-1]->next=null;
        c[0]->last=null;
        edge * now=c[0];
        for (;;)
        {
            if (now->next==null) break;
            if (now->val==now->next->val)
            {
                now->sum+=now->next->sum;
                now->next->next->last=now;
                now->next=now->next->next;
                continue;
            }
            int tt=now->sum/k;
            if (now->val!=not_cnt) ans-=tt*k;
            now->sum%=k;
            if (now->sum==0)
            {
                now->last->next=now->next;
                now->next->last=now->last;
                now=now->last;
                if (now==null) now=now->next;
                continue;
            }
            now=now->next;
        }
        int tt=now->sum/k;
        if (now->val!=not_cnt) ans-=tt*k;
        now->sum%=k;
        cout<<ans<<endl;
    }
    return 0;
}