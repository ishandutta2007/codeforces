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
char s[200005];
bool cx[27];
signed main()
{
	int t,n;
	int ans=0,x;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		if(n==2)
		{
		    printf("-1\n");
		    continue;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j;k<=n-1;k++)printf("%d ",n*(k)+j);
			for(int k=1;k<=j;k++)printf("%d ",(k-1)*n+j);
			printf("\n");
		}
	}
	return 0;
}