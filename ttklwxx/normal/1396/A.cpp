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
int a[100005];
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1)
	{
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("%lld\n",-a[1]);
		return 0;
	}
	printf("%lld %lld\n",1LL,n);
	for(int i=1;i<=n-1;i++)printf("%lld ",-n*a[i]);
	printf("%lld\n",0LL);
	printf("%lld %lld\n",1LL,n-1);
	for(int i=1;i<=n-1;i++)printf("%lld ",(n-1)*a[i]);
	printf("\n");
	printf("%lld %lld\n",n,n);
	printf("%lld\n",-a[n]);
	return 0;
}