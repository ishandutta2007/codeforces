#include<iostream>
#include<cstdio>
#include<cmath>
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
int a[200001];
int main()
{
	int t,n,sum;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		flag=false;
		for(int i=1;i<=n;i++)if(a[i]!=i)
		{
			flag=true;
			break;
		}
		if(flag==false)
		{
			printf("0\n");
			continue;
		}
		sum=0;
		for(int i=1;i<=n;i++)if(a[i]==i)
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==i)sum--;
			else break;
		}
		for(int i=n;i>=1;i--)
		{
			if(a[i]==i)sum--;
			else break;
		}
		if(sum<=0)
		{
			printf("1\n");
			continue;
		}
		printf("2\n");
	}
	return 0;
}