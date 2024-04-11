#include<iostream>
#include<cstdio>
#define mod 998244353
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
	int ch[2],het,laz1,laz2,laz3;
}a[20000004];
int cnt;
void pushdown(int k,int l,int r)
{
	if(!a[k].ch[0])a[k].ch[0]=++cnt;
	if(!a[k].ch[1])a[k].ch[1]=++cnt;
	int x=a[k].ch[0],y=a[k].ch[1],mid=(l+r)>>1;
	if(a[k].laz1==1)
	{
		a[x].het=0;
		a[x].laz1=1;
		a[x].laz2=0;
		a[y].het=0;
		a[y].laz1=1;
		a[y].laz2=0;
		a[k].laz1=0; 
	}
	if(a[k].laz3==1)
	{
		a[x].het=mod-a[x].het;
		a[x].laz3=1-a[x].laz3;
		a[x].laz2=mod-a[x].laz2;
		a[y].het=mod-a[y].het;
		a[y].laz3=1-a[y].laz3;
		a[y].laz2=mod-a[y].laz2;
		a[k].laz3=0;
	}
	if(a[k].laz2!=0)
	{
		a[x].het=(a[x].het+1LL*(mid-l+1)*a[k].laz2%mod)%mod;
		a[x].laz2=(a[x].laz2+a[k].laz2)%mod;
		a[y].het=(a[y].het+1LL*(r-mid)*a[k].laz2%mod)%mod;
		a[y].laz2=(a[y].laz2+a[k].laz2)%mod;
		a[k].laz2=0;
	}
}
void jia(int ql,int qr,int l,int r,int &k,int x)
{
	if(l>qr||r<ql)return;
	if(k==0)k=++cnt;
	if(l>=ql&&r<=qr)
	{
		a[k].het=(a[k].het+1LL*(r-l+1)*x)%mod;
		a[k].laz2=(a[k].laz2+x)%mod;
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	jia(ql,qr,l,mid,a[k].ch[0],x);
	jia(ql,qr,mid+1,r,a[k].ch[1],x);
	a[k].het=(a[a[k].ch[0]].het+a[a[k].ch[1]].het)%mod;
}
void fan(int ql,int qr,int l,int r,int &k)
{
	if(l>qr||r<ql)return;
	if(k==0)k=++cnt;
	if(l>=ql&&r<=qr)
	{
		a[k].het=mod-a[k].het;
		a[k].laz3=1-a[k].laz3;
		a[k].laz2=mod-a[k].laz2;
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	fan(ql,qr,l,mid,a[k].ch[0]);
	fan(ql,qr,mid+1,r,a[k].ch[1]);
	a[k].het=(a[a[k].ch[0]].het+a[a[k].ch[1]].het)%mod;
}
void tui(int ql,int qr,int l,int r,int &k)
{
	if(l>qr||r<ql)return;
	if(k==0)k=++cnt;
	if(l>=ql&&r<=qr)
	{
		a[k].het=0;
		a[k].laz1=1;
		a[k].laz2=0;
		a[k].laz3=0;
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	tui(ql,qr,l,mid,a[k].ch[0]);
	tui(ql,qr,mid+1,r,a[k].ch[1]);
	a[k].het=(a[a[k].ch[0]].het+a[a[k].ch[1]].het)%mod;
}
int qz[200005];
int main()
{
	int n,sth,rt=0;
	n=read();
	for(int i=1;i<=n;i++)qz[i]=read();
	//jia(0,0,0,1000000000,rt,1);
	for(int i=1;i<=n;i++)
	{
		sth=a[rt].het;
		if(i==1)sth=1;
		//printf("%d\n",sth);
		fan(1,qz[i],0,1000000000,rt);
		jia(1,qz[i],0,1000000000,rt,sth);
		if(qz[i]<qz[i-1])
		{
			tui(qz[i]+1,qz[i-1],0,1000000000,rt);
		}
	}
	printf("%d\n",a[rt].het);
	return 0;
}