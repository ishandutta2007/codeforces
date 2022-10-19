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
int a[500005];
int dpl[500005],dpr[500005];
int f[500005],n;
void gx(int i)
{
	if(i>n)return;
	int dz=0,dj=n+1;
	if(dpl[i-1]<a[i])dz=max(dz,a[i-1]);
	if(a[i-1]<a[i])dz=max(dz,dpr[i-1]);
	if(a[i]<dpr[i-1])dj=min(dj,a[i-1]);
	if(a[i]<a[i-1])dj=min(dj,dpl[i-1]);
	if(dz==dpr[i]&&dj==dpl[i])return;
	dpr[i]=dz;
	dpl[i]=dj;
	f[i]=0;
	if(dj<=n||dz>=1)
	{
		gx(i+1);
		f[i]=f[i+1]+1;
	}
	return;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		dpr[i]=n+1;
		dpl[i]=0;
		gx(i+1);
		f[i]=f[i+1]+1;
		ans+=f[i];
	} 
	printf("%lld\n",ans);
	return 0;
}