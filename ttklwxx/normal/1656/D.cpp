#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
signed main()
{
	int t,n,k,now;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n<=2)
		{
			printf("-1\n");
			continue;
		}
		if(n%2==1)
		{
			printf("2\n");
			continue;
		}
		now=1;
		while(n%2==0)n/=2,now*=2;
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",min(n,now*2));
	} 
	return 0;
}