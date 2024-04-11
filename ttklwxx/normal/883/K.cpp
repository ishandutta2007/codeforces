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
int f[200005],g[200005],gg[200005];
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)
	{
		g[i]=read();
		f[i]=read();
		f[i]+=g[i];
		gg[i]=g[i];
	}
	for(int i=2;i<=n;i++)f[i]=min(f[i],f[i-1]+1);
	for(int i=n-1;i>=1;i--)f[i]=min(f[i],f[i+1]+1);
	for(int i=1;i<=n;i++)if(f[i]<g[i])
	{
		printf("-1\n");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=f[i]-g[i];
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)cout<<f[i]<<endl;
	return 0;
}