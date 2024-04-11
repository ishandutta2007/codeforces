#include<iostream>
#include<cstdio>
#include<algorithm>
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
int ans[500005];
signed main()
{
	int t,n,het=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		het=0;
		for(int i=1;i<=n;i++)a[i]=read(),het+=a[i];
		if(het%(n*(n+1)/2)!=0)
		{
			printf("NO\n");
			continue;
		}
		het/=n*(n+1)/2;
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if((het+a[i]-a[i%n+1])%n!=0)
			{
				flag=false;
				break;
			}
			ans[i]=(het+a[(i+n-2)%n+1]-a[i])/n;
			if(ans[i]<=0)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}