/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
struct Node
{
    int id,l,r;
}q[V];
bool cmp(Node x,Node y)
{return x.l<y.l;}
int a[V],ct;
void init(){ct=0;}
void sink(int k)
{
    while(2*k<=ct)
    {
        int id=k;
        if(q[a[2*k]].r<q[a[id]].r)id=2*k;
        if(2*k+1<=ct&&q[a[2*k+1]].r<q[a[id]].r)id=2*k+1;
        if(id==k)break;swap(a[id],a[k]);k=id;
    }
}
void up(int k)
{
    while(k!=1)
    {
        if(q[a[k]].r<q[a[k/2]].r)
        {swap(a[k],a[k/2]);k/=2;}
        else break;
    }
}
int top(){return a[1];}
void pop(){a[1]=a[ct];ct--;sink(1);}
void add(int x){a[++ct]=x;up(ct);}
int ans[V],ret,n,m,x,y,i;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            q[i].id=i;
            q[i].l=n+1-x;
            q[i].r=y;
        }
        sort(q,q+m,cmp);
        int ret=0;
        int p=0;
        for(i=1;i<=n;i++)
        {
            while(ct>0&&q[top()].r<i)
            pop();
            while(p<m&&q[p].l<=i)
            {add(p);p++;}
            if(ct!=0)
            {
                ans[ret++]=q[top()].id+1;
                pop();
            }
        }
        printf("%d\n",ret);
        sort(ans,ans+ret);
        for(i=0;i<ret;i++)printf("%d ",ans[i]);puts("");
    }
}