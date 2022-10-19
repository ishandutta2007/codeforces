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
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=i;j++)printf("%d ",j);
			printf("%d ",1);
			for(int j=i+1;j<=n;j++)printf("%d ",j);
			printf("\n");
		}
	}
	return 0;
}