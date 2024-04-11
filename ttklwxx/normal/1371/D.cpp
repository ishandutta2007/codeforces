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
int h[1001],l[1001];
signed main()
{
	int t,n,k,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		if(k%n==0)ans=0;
		else ans=2;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((j-i+n)%n<k/n)printf("1");
				else if((j-i+n)%n==k/n&&i<=k%n)printf("1");
				else printf("0");
			}
			printf("\n");
		}
	} 
	return 0;
}