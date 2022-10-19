#include<iostream>
#include<cstdio>
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
int main()
{
	int t,n;
	t=read();
	for(int gre=1;gre<=t;gre++)
	{
		n=read();
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		printf("8");
		for(int i=1;i<=n-1;i++)printf("9");
		printf("\n");
	}
	return 0;
}