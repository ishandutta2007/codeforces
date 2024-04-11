#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
int fa[5001],bs,ans;
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
int fgen(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=fgen(fa[x]);
}
struct bian
{
	int dd1,dd2,qz;
}a[5000001];
bool bi(bian x,bian y)
{
	return x.qz<y.qz;
}
int k[20000],tx[20001],ty[20001];
int ansx[20001],ansy[20001],cnt;
signed main()
{
	int n,m;
	n=read();
	for(int i=2;i<=n+1;i++)
	{
		tx[i]=read();
		ty[i]=read();
	}
	for(int i=1;i<=n+1;i++){fa[i]=i;}
	m=0;
	for(int i=2;i<=n+1;i++)
	{
		a[++m].dd1=1;
		a[m].dd2=i;
		a[m].qz=read();
	}
	for(int i=2;i<=n+1;i++)k[i]=read();
	for(int i=2;i<=n+1;i++)
	{
		for(int j=i+1;j<=n+1;j++)
		{
			a[++m].dd1=i;
			a[m].dd2=j;
			a[m].qz=(abs(tx[i]-tx[j])+abs(ty[i]-ty[j]))*(k[i]+k[j]);
		}
	}
	sort(a+1,a+m+1,bi);
	int tb=0,x,y;
	for(int i=1;i<=m;i++)
	{
		x=fgen(a[i].dd1);
		y=fgen(a[i].dd2);
		if(x==y)continue;
		ans+=a[i].qz;
		fa[x]=y;
		bs++;
		ansx[++cnt]=a[i].dd1;
		ansy[cnt]=a[i].dd2;
		if(a[i].dd1==1)tb++;
		if(bs==n){break;}
	}
	printf("%lld\n",ans);
	printf("%lld\n",tb);
	for(int i=1;i<=cnt;i++)if(ansx[i]==1)printf("%lld ",ansy[i]-1);
	printf("\n%lld\n",n-tb);
	for(int i=1;i<=cnt;i++)if(ansx[i]!=1)printf("%lld %lld\n",ansx[i]-1,ansy[i]-1);
	return 0;
}