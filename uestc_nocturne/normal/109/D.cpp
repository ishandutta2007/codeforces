#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
int check(int x)
{
    while(x>0)
    {
        if(x%10!=4&&x%10!=7)return 0;
        x/=10;
    }
    return 1;
}
const int V=100100;
struct Node{int id,va;}q[V];
bool cmpva(Node x,Node y)
{
    if(x.va!=y.va)return x.va<y.va;
    return x.id<y.id;
}
bool cmpid(Node x,Node y)
{
    return x.id<y.id;
}
struct Elf{int x,y;}ans[2*V];
int pos[V],now[V],a[V];
struct Noc{int l,r,ma;}p[4*V];
void init(int nu,int l,int r)
{
    p[nu].l=l;
    p[nu].r=r;
    if(l==r)
    {
        p[nu].ma=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(nu*2,l,mid);
    init(nu*2+1,mid+1,r);
    p[nu].ma=max(p[nu*2].ma,p[nu*2+1].ma);
}
void update(int nu,int po,int x)
{
    if(p[nu].l==po&&p[nu].r==po)
    {
        p[nu].ma=x;return;
    }
    int mid=(p[nu].l+p[nu].r)/2;
    if(po<=mid)update(nu*2,po,x);
    else update(nu*2+1,po,x);
    p[nu].ma=max(p[nu*2].ma,p[nu*2+1].ma);
}
int read(int nu)
{
    if(p[nu].ma==0)return -1;
    if(p[nu].l==p[nu].r)return p[nu].l;
    int mid=(p[nu].l+p[nu].r)/2;
    if(p[nu*2].ma!=0)return read(nu*2);
    else return read(nu*2+1);
}
int n,i,y,ct;
int main()
{
    while(~scanf("%d",&n))
    {
        int id=-1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&q[i].va);
            q[i].id=i;
            if(check(q[i].va)==1)id=i;
        }
        sort(q,q+n,cmpva);
        for(i=0;i<n;i++)now[q[i].id]=i;
        for(i=0;i<n;i++)pos[i]=q[i].id;
        sort(q,q+n,cmpid);
        for(i=0;i<n;i++)
        {
            if(i==now[i])a[i]=0;
            else a[i]=1;
        }
        a[id]=0;
    //  for(i=0;i<n;i++)printf("%d ",a[i]);puts("");
        init(1,0,n-1);
        bool can=true;
        int ct=0;
        while(1)
        {
            i=read(1);
            if(i==-1)break;
            if(id==-1)
            {can=false;break;}
            y=now[i];
        //  for(int j=0;j<n;j++)printf("%d ",now[j]);puts("");
        //  printf("Swap : %d %d %d\n",i,y,id);
            if(y==i)
            {
                update(1,i,0);
                continue;
            }
            if(y==id)
            {
                ans[ct].x=i;
                ans[ct++].y=id;
                now[i]=now[id];
                now[id]=id;
                int tp=id;
                id=i;
                pos[now[i]]=i;
                pos[now[tp]]=tp;
                update(1,tp,0);
                update(1,id,0);
            }
            else
            {
                ans[ct].x=y;
                ans[ct++].y=id;
                ans[ct].x=i;
                ans[ct++].y=y;
                int tp=id;
                id=i;
                now[i]=now[tp];
                now[tp]=now[y];
                now[y]=y;
                pos[now[i]]=i;
                pos[now[tp]]=tp;
                update(1,y,0);
                update(1,id,0);
                update(1,tp,1);
            }
        }
        if(!can)puts("-1");
        else
        {
            printf("%d\n",ct);
            for(i=0;i<ct;i++)
            printf("%d %d\n",ans[i].x+1,ans[i].y+1);
        }
    }
}