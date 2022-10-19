#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
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
	int l,r,maxn;
}t[800004];
void build(int l,int r,int k)
{
	t[k].l=l;
	t[k].r=r;
	t[k].maxn=1000000000;
	if(l==r)return;
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void change(int x,int k,int y)
{
	if(t[k].l>x||t[k].r<x)return;
	if(t[k].l==t[k].r)
	{
		t[k].maxn=min(t[k].maxn,y);
		return;
	}
	change(x,k<<1,y);
	change(x,k<<1|1,y);
	t[k].maxn=min(t[k<<1].maxn,t[k<<1|1].maxn);
}
int query(int l,int r,int k)
{
	if(t[k].l>r||t[k].r<l)return 1000000000;
	if(t[k].l>=l&&t[k].r<=r)return t[k].maxn;
	return min(query(l,r,k<<1),query(l,r,k<<1|1));
}
struct atree
{
	int l,r,het,laz;
}a[800004];
void builda(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].het=0;
	a[k].laz=0;
	if(a[k].l==a[k].r)return;
	builda(l,(l+r)>>1,k<<1);
	builda(((l+r)>>1)+1,r,k<<1|1);
}
void changea(int l,int r,int k)
{
	//printf("vis:%lld %lld %lld\n",l,r,k);
	if(a[k].l>r||a[k].r<l)return;
	if(a[k].l>=l&&a[k].r<=r)
	{
		a[k].het=a[k].r-a[k].l+1;
		a[k].laz=1;
		//printf("???%lld %lld\n",a[k].l,a[k].r);
		return;
	}
	if(a[k].laz==1)
	{
		a[k<<1].het=a[k<<1].r-a[k<<1].l+1;
		a[k<<1].laz=1;
		a[k<<1|1].het=a[k<<1|1].r-a[k<<1|1].l+1;
		a[k<<1|1].laz=1;
		a[k].laz=0;
	}
	changea(l,r,k<<1);
	changea(l,r,k<<1|1);
	a[k].het=a[k<<1].het+a[k<<1|1].het;
} 
int querya(int x,int k)
{
	if(a[k].l>x||a[k].r<x)return 0;
	if(a[k].l==a[k].r)return a[k].het;
	if(a[k].laz==1)
	{
		a[k<<1].het=a[k<<1].r-a[k<<1].l+1;
		a[k<<1].laz=1;
		a[k<<1|1].het=a[k<<1|1].r-a[k<<1|1].l+1;
		a[k<<1|1].laz=1;
		a[k].laz=0;
	}
	if(a[k<<1].r>=x)return querya(x,k<<1);
	else return querya(x,k<<1|1);
}
int findl(int k,int x)
{
	if(a[k].l>x)return -1;
	if(a[k].het==a[k].r-a[k].l+1)return -1;
	if(a[k].l==a[k].r)return a[k].l;
	int sth=findl(k<<1|1,x);
	if(sth!=-1)return sth;
	return findl(k<<1,x);
}
int findr(int k,int x)
{
	if(a[k].r<x)return -1;
	if(a[k].het==a[k].r-a[k].l+1)return -1;
	if(a[k].l==a[k].r)return a[k].l;
	int sth=findr(k<<1,x);
	if(sth!=-1)return sth;
	return findr(k<<1|1,x);
}
signed main()
{
	int n,q,opt,x,y,z;
	n=read();
	q=read();
	build(1,n,1);
	builda(1,n,1);
	for(int i=1;i<=q;i++)
	{
		opt=read();
		if(opt==0)
		{
			x=read();
			y=read();
			z=read();
			if(z==0)
			{
				//printf("orz%lld %lld\n",x,y);
				changea(x,y,1);
			}
			else
			{
				change(x,1,y);
			}
		}
		else if(opt==1)
		{
			x=read();
			//printf("%d\n",querya(x,1));
			if(querya(x,1)==1)
			{
				printf("NO\n");
				continue;
			}
			y=findl(1,x-1);
			if(y==-1)y=1;
			else y=y+1;
			z=findr(1,x+1);
			if(z==-1)z=n;
			else z=z-1;
			if(query(y,x,1)<=z)printf("YES\n");
			else printf("N/A\n");
		}
	}
	return 0;
}