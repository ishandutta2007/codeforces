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
int a[5005];
int now[5005];
signed main()
{
	int t,n,ans,nans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),now[i]=0;
		ans=0;
		for(int c=n;c>=1;c--)
		{
			nans=0;
			for(int i=c-2;i>=1;i--)
			{
				nans+=now[i+1];
				if(a[i]<a[c])ans+=nans;
			}
			//printf("orz%d\n",ans);
			for(int i=1;i<=n;i++)
			{
				if(a[i]>a[c])now[i]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}