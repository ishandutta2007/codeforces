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
int r[V];
int find(int x)
{
    if(r[x]!=x)r[x]=find(r[x]);
    return r[x];
}
int ret[V];
struct Node
{
    int l,r,va;
}q[4*V];
bool cmp(Node x,Node y)
{return x.va<y.va;}
int n,tmp[V];
const int oo=1000000000;
void init()
{
    for(int i=1;i<=n+1;i++)r[i]=i,tmp[i]=oo;
}
void cover(int id)
{
   // printf("%d %d %d %d\n",id,q[id].l,q[id].r,q[id].va);
    int now=q[id].l;
    while(now<=q[id].r&&now<=n)
    {
      //  cout<<now<<" "<<r[now]<<endl;
        if(r[now]==now)
        {
            tmp[now]=q[id].va;
            r[now]=now+1;
        }
        now=find(now);
    }
}
int a[V],b[V],pos[V];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
        int ct=0;
        for(int i=1;i<=n;i++)
        {
            if(pos[b[i]]>=i)
            {
                q[ct].l=1;
                q[ct].r=i;
                q[ct++].va=pos[b[i]]-i-1;
                q[ct].l=n+1-(pos[b[i]]-i);
                q[ct].r=n;
                q[ct++].va=-(n+1-(pos[b[i]]-i));
            }
            if(pos[b[i]]<=i)
            {
                q[ct].l=i-pos[b[i]]+1;
                q[ct].r=i;
                q[ct++].va=-(i-pos[b[i]]+1);
            }
        }
        init();
        sort(q,q+ct,cmp);
        for(int i=0;i<ct;i++)cover(i);
        for(int i=1;i<=n;i++)ret[i]=tmp[i]+i;
        ct=0;
        for(int i=1;i<=n;i++)
        {
            if(pos[b[i]]>=i)
            {
                q[ct].l=i+1;
                q[ct].r=n+1-(pos[b[i]]-i);
                q[ct++].va=n-pos[b[i]]+i+1;
            }
            if(pos[b[i]]<=i)
            {
                q[ct].l=1;
                q[ct].r=i-pos[b[i]]+1;
                q[ct++].va=i-pos[b[i]]+1;
                q[ct].l=i+1;
                q[ct].r=n;
                q[ct++].va=i+1+n-pos[b[i]];
            }
        }
        init();
        sort(q,q+ct,cmp);
        for(int i=0;i<ct;i++)cover(i);
        for(int i=1;i<=n;i++)ret[i]=min(ret[i],tmp[i]-i);
        for(int i=1;i<=n;i++)printf("%d\n",ret[i]);
    }
}