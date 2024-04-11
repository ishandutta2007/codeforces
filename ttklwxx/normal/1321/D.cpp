// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#define inf 2147483647
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch==' '||ch=='\n')ch=getchar();
	if(ch=='-')
	{
		f=-1;
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
	int l,r,minp,minn;
}a[1000004];
int dis[300001];
int n,m,s;
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
    a[k].minn=inf;
    a[k].minp=l;
    if(l!=r)
    {
    	build(l,(l+r)>>1,k<<1);
    	build(((l+r)>>1)+1,r,k<<1|1);
    }
    return;
}
void change(int y,int k,int x)
{
	if(a[k].l==a[k].r)
	{
		a[k].minn=x;
		return;
	}
	if(((a[k].l+a[k].r)>>1)>=y)change(y,k<<1,x);
	else change(y,k<<1|1,x);
    if(a[k<<1].minn<=a[k<<1|1].minn)
    {
    	a[k].minn=a[k<<1].minn;
    	a[k].minp=a[k<<1].minp;
    }
    else
    {
    	a[k].minn=a[k<<1|1].minn;
    	a[k].minp=a[k<<1|1].minp;
    }
}
struct bbian
{
	int u,v,w,nex;
}b[500001],c[500001];
int head[300001],tmp;
int headc[300001],tmpc;
void addb(int x,int y,int z)
{
	b[++tmp].u=x;
	b[tmp].v=y;
	b[tmp].w=z;
	b[tmp].nex=head[x];
	head[x]=tmp;
}
void addc(int x,int y,int z)
{
	c[++tmpc].u=x;
	c[tmpc].v=y;
	c[tmpc].w=z;
	c[tmpc].nex=headc[x];
	headc[x]=tmpc;
}
int l[200001];
int main()
{
    n=read();
    m=read();
	int x,y,z;
    for(int i=1;i<=m;i++)
    {
    	x=read();
    	y=read();
    	z=1;
    	addb(y,x,z);
    	addc(x,y,z);
    }
    int k;
    k=read();
    for(int i=1;i<=k;i++)l[i]=read();
    build(1,n,1);
    for(int i=1;i<=n;i++)dis[i]=inf;
    s=l[k];
    dis[s]=0;
    change(s,1,0);
    while(a[1].minn<inf)
    {
    	x=a[1].minp;
    	change(x,1,inf);
    	if(dis[x]==inf)continue;
    	for(int i=head[x];i;i=b[i].nex)
    	{
    		if(dis[b[i].v]>dis[x]+b[i].w)
    		{
    			dis[b[i].v]=dis[x]+b[i].w;
    			change(b[i].v,1,dis[b[i].v]);
    		}
    	}
    }
    int minn=0,maxn=0;
    for(int i=1;i<=k-1;i++)
    {
    	x=0;
		if(dis[l[i+1]]!=dis[l[i]]-1)
		{
			minn++;
			maxn++;
			continue;
		}
		for(int j=headc[l[i]];j;j=c[j].nex)
		{
			if(dis[c[j].v]==dis[l[i]]-1&&c[j].v!=l[i+1])x++;
		}
		if(x>=1)maxn++;
	}
	printf("%d %d\n",minn,maxn);
    return 0;
}