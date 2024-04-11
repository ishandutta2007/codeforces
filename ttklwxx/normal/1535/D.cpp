#include<iostream>
#include<cstdio>
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
int n;
struct tree
{
	int l,r,sl,dy;
	char zt;
}a[1200005];
char s[400005];
int zy[400005];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	if(l==r)
	{
		a[k].sl=1;
		return;
	}
	a[k].dy=n-2*n/(a[k].r-a[k].l+1)+a[k].r/(a[k].r-a[k].l+1);
	zy[a[k].dy]=k;
	a[k].zt=s[a[k].dy];
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	if(a[k].zt=='0')a[k].sl=a[k<<1].sl;
	else if(a[k].zt=='1')a[k].sl=a[k<<1|1].sl;
	else a[k].sl=a[k<<1].sl+a[k<<1|1].sl;
}
void change(int x,int len,int k,char y)
{
	if(k==x)
	{
		a[k].zt=y;
		if(a[k].zt=='0')a[k].sl=a[k<<1].sl;
		else if(a[k].zt=='1')a[k].sl=a[k<<1|1].sl;
		else a[k].sl=a[k<<1].sl+a[k<<1|1].sl;
		return;
	}
	if(x/((n/len)/(2*n/(a[k].r-a[k].l+1)))%2==0)change(x,len,k<<1,y);
	else change(x,len,k<<1|1,y);
	if(a[k].zt=='0')a[k].sl=a[k<<1].sl;
	else if(a[k].zt=='1')a[k].sl=a[k<<1|1].sl;
	else a[k].sl=a[k<<1].sl+a[k<<1|1].sl;
}
int main()
{
	int k;
	k=read();
	n=(1<<k);
	scanf("%s",s+1);
	build(1,n,1);
	int q,x;
	char c;
	q=read();
	for(int i=1;i<=q;i++)
	{
		x=read();
		c=getchar();
		while(c!='0'&&c!='1'&&c!='?')c=getchar();
		x=zy[x];
		change(x,a[x].r-a[x].l+1,1,c);
		printf("%d\n",a[1].sl);
	}
	return 0;
}