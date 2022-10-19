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
signed main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n%2==1)
		{
			printf("Bob\n");
			continue;
		}
		flag=false;
		for(int i=1;i<=20;i++)if(n==(1LL<<(2*i-1)))
		{
			flag=true;
			break;
		}
		if(flag==true)
		{
			printf("Bob\n");
			continue;
		}
		printf("Alice\n");
	}
	return 0;
}