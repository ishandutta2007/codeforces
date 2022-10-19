#include<iostream>
#include<cstdio>
#include<map>
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
int a[200005],zs[200005],gre[200005];
map<int,int>cx;
int main()
{
	int t,n,ans=0,sl=0,nsl=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),cx[a[i]]++;
		for(int i=1;i<=n;i++)
		{
			if(cx[a[i]]==0)continue;
			zs[cx[a[i]]]++;
			cx[a[i]]=0;
		}
		for(int i=1;i<=n;i++)gre[i]=gre[i-1]+zs[i]*i;
		for(int i=2;i<=n;i++)zs[i]+=zs[i-1];
		ans=n;
		sl=0;
		nsl=0;
		for(int i=n;i>=1;i--)
		{
			nsl+=sl;
			ans=min(ans,nsl+gre[i-1]);
			sl+=zs[i]-zs[i-1];
		}
		printf("%d\n",ans);
		cx.clear();
		for(int i=1;i<=n;i++)zs[i]=0,gre[i]=0;
	}
	return 0;
}