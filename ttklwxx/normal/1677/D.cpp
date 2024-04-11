#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 998244353
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
int a[1000005];
signed main()
{
	int t,n,k,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		flag=false;
		for(int i=n-k+1;i<=n;i++)
		{
			if(a[i]!=0&&a[i]!=-1)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)
		{
			printf("0\n");
			continue;
		}
		ans=1;
		for(int i=1;i<=k;i++)ans=ans*i%mod;
		for(int i=1;i<=n-k;i++)
		{
			if(a[i]>=i)
			{
				flag=true;
				break;
			}
			if(a[i]==-1)ans=1LL*ans*(i+k)%mod;
			else if(a[i]==0)ans=1LL*ans*(k+1)%mod;
		}
		if(flag==true)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}