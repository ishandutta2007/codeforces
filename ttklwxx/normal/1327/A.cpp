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
signed main()
{
	int t,n,k;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		k=read();
		if(n<k*k)
		{
			printf("NO\n");
			continue;
		}
		if(n%2!=k%2)
		{
		    printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}