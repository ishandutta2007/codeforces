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
int a[200001];
signed main()
{
	int t,n,minn,tmax;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		for(int j=1;j<=n;j++)
		{
			a[j]=read();
		}
		minn=1121131433448687LL;
		tmax=0;
		for(int j=n-1;j>=1;j--)
		{
			minn=min(minn,a[j+1]);
		    tmax=max(tmax,a[j]-minn);
		}
		for(int j=0;;j++)
		{
			if((1LL<<j)>tmax)
			{
				printf("%lld\n",j);
				break; 
			}
		}
	} 
	return 0;
}