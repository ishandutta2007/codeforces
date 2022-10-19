#include<iostream>
#include<cstdio>
#include<cstdlib>
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
int a[100005],dp[100005];
int main()
{
	int t,n,k,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		if(n==4&&k==3)
		{
			printf("-1\n");
			continue;
		}
		if(k==n-1)
		{
			printf("%d %d\n",0,1);
			printf("%d %d\n",2,n-4);
			printf("%d %d\n",3,n-3);
			printf("%d %d\n",n-1,n-2);
			for(int i=4;i<=n/2-1;i++)printf("%d %d\n",i,n-1-i);
			continue;
		}
		if(k==0)
		{
			for(int i=0;i<=n/2-1;i++)printf("%d %d\n",i,n-1-i);
			continue;
		}
		printf("0 %d\n",n-1-k);
		for(int i=1;i<=n/2-1;i++)
		{
			if(i!=n-1-k&&i!=k)printf("%d %d\n",i,n-1-i);
		}
		printf("%d %d\n",n-1,k);
	}
	return 0;
}