#include<iostream>
#include<cstdio>
#include<vector>
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
	int n,m;
	n=read();
	m=read();
	printf("%d\n",n*m+n+m-3);
	for(int i=1;i<=m-1;i++)printf("L");
	for(int i=1;i<=n-1;i++)printf("U");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			if(i%2==1)printf("R");
			else printf("L");
		}
		if(i!=n)printf("D");
	}
	return 0;
}