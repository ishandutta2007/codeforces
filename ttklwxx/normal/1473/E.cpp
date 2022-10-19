#include<iostream>
#include<cstdio>
#define int long long
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
	int l,r,minn,mpos;
}a[3200004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].minn=1121131433448687LL;
	a[k].mpos=l;
	if(l==r)return;
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void change(int x,int k,int y)
{
	if(a[k].l==a[k].r)
	{
		a[k].minn=y;
		return;
	}
	if(x<=a[k<<1].r)change(x,k<<1,y);
	else change(x,k<<1|1,y);
	if(a[k<<1].minn<a[k<<1|1].minn)
	{
		a[k].minn=a[k<<1].minn;
		a[k].mpos=a[k<<1].mpos;
	}
	else
	{
		a[k].minn=a[k<<1|1].minn;
		a[k].mpos=a[k<<1|1].mpos;
	}
	return;
}
struct bbian
{
	int u,v,w,nex;
}b[4000004];
int head[800005],tmp;
void addb(int x,int y,int z)
{
	b[++tmp].u=x;
	b[tmp].v=y;
	b[tmp].w=z;
	b[tmp].nex=head[x];
	head[x]=tmp;
}
int dis[800005],tans[800005];
signed main()
{
	int n,m,s,x,y,z;
	n=read();
	for(int i=1;i<=n;i++)tans[i]=1121131433448687LL;
	m=read();
	s=1;
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		z=read();
		if(x==1)tans[y]=min(tans[y],z);
		if(y==1)tans[x]=min(tans[x],z);
		addb(x,y,z);
		addb(x+n,y+n,z);
		addb(x+2*n,y+2*n,z);
		addb(x+3*n,y+3*n,z);
		addb(x,y+n,0);
		addb(x,y+2*n,2*z);
		addb(x+n,y+3*n,2*z);
		addb(x+2*n,y+3*n,0);
		addb(y,x,z);
		addb(y+n,x+n,z);
		addb(y+2*n,x+2*n,z);
		addb(y+3*n,x+3*n,z);
		addb(y,x+n,0);
		addb(y,x+2*n,2*z);
		addb(y+n,x+3*n,2*z);
		addb(y+2*n,x+3*n,0);
	}
	n=4*n;
	build(1,n,1);
	for(int i=1;i<=n;i++)dis[i]=1121131433448687LL;
	dis[s]=0;
	change(s,1,0);
	while(a[1].minn!=1121131433448687LL)
	{
		x=a[1].mpos;
		change(x,1,1121131433448687LL);
		for(int i=head[x];i;i=b[i].nex)
		{
			if(dis[x]+b[i].w<dis[b[i].v])
			{
				dis[b[i].v]=dis[x]+b[i].w;
				change(b[i].v,1,dis[b[i].v]);
			} 
		}
	}
	n=n/4;
	for(int i=2;i<=n;i++)printf("%lld ",min(dis[i+3*n],tans[i]));
	return 0;
}