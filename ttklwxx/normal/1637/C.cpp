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
int a[200005],sy[200005];
signed main()
{
	int t,n,ans=0,zq=0,nex,jsl=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		jsl=0;
		for(int i=2;i<=n-1;i++)
		{
			ans+=(a[i]+1)/2;
			if(a[i]%2==1)jsl++;
		}
		if(n==3)
		{
			if(a[2]%2==0)printf("%lld\n",a[2]/2);
			else printf("-1\n");
			continue;
		}
		flag=false;
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]>=2)flag=true;
		}
		if(flag==false)
		{
			printf("-1\n");
			continue;
		}
		if(jsl==1)
		{
			flag=true;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=2&&a[i]%2==0)
				{
					flag=false;
					break;
				}
			}
			if(flag==false)
			{
				printf("%lld\n",ans);
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]==3)
				{
					flag=false;
					break;
				}
			}
			if(flag==false)printf("-1\n");
			else printf("%lld\n",ans+1);
		}
		else printf("%lld\n",ans);
	}
	return 0;
}