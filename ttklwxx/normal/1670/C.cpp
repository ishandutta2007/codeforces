#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
#define mod 1000000007
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
int a[1000005],b[1000005],c[1000005],dy[1000005],dc[1000005];
bool vis[1000005];
signed main()
{
	int t,n,k,ans,x;
	bool flag;
	char ch;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read(),dy[a[i]]=b[i];
		for(int i=1;i<=n;i++)c[i]=read(),dc[a[i]]=c[i];
		for(int i=1;i<=n;i++)vis[i]=false;
		ans=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==true)continue;
			if(i==dy[i])
			{
				vis[i]=true;
				continue;
			}
			x=dy[i];
			vis[i]=true;
			flag=true;
			if(dc[i]!=0)flag=false;
			while(x!=i)
			{
				vis[x]=true;
				if(dc[x]!=0)flag=false;
				x=dy[x];
			}
			if(flag==true)ans=ans*2%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}