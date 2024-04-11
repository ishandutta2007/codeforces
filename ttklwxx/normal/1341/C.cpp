#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
struct tree
{
    int l,r,maxn;
}a[800004];
void build(int l,int r,int k)
{
     a[k].l=l;
     a[k].r=r;
     a[k].maxn=0;
     if(l==r)return;
     build(l,(l+r)>>1,k<<1);
     build(((l+r)>>1)+1,r,k<<1|1);
}
void change(int x,int k,int y)
{
     if(a[k].l==a[k].r)
     {
         a[k].maxn=y;
         return;
     }
     if(x<=a[k<<1].r)change(x,k<<1,y);
     else change(x,k<<1|1,y);
     a[k].maxn=max(a[k<<1].maxn,a[k<<1|1].maxn);
}
int yt[400002],pos[400002];
set<int>se;
signed main()
{
    int t,n,x,maxn=0;
    t=read();
    bool flag=false;
    for(int greg=1;greg<=t;greg++)
    {
        n=read();
        build(1,n,1);
        for(int i=1;i<=n;i++)pos[read()]=i;
        for(int i=1;i<=n;i++)yt[i]=0;
        flag=false;
        maxn=0;
        se.clear(); 
        for(int i=1;i<=n;i++)se.insert(i);
        for(int i=1;i<=n;i++)
        {
            se.erase(pos[i]);
            if(yt[pos[i]]<a[1].maxn)
            {
                printf("No\n");
                flag=true;
                break;
            }
            if(se.lower_bound(pos[i])!=se.end()){x=*se.lower_bound(pos[i]);
            yt[x]+=yt[pos[i]]+1;
            change(x,1,yt[x]);}
            yt[pos[i]]=0;
            change(pos[i],1,0);
        }
        if(flag==true)continue;
        printf("Yes\n");
    }
    //system("pause>nul");
    return 0;
}