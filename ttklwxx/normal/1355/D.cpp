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
signed main()
{
	int n,s;
	n=read();
	s=read();
	if(s>=2*n)
	{
		printf("YES\n");
		for(int i=1;i<=n-1;i++)printf("2 ");
		printf("%d\n",s-2*(n-1));
		printf("1\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}