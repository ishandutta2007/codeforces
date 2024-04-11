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
int a[100001];
int main()
{
	int t,n,x,s;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		for(int i=1;i<=n;i++)a[i]=read();
		s=0;
		if(x==n)
		{
			for(int i=1;i<=n;i++)s+=a[i];
			if(s%2==1)printf("Yes\n");
			else printf("No\n");
			continue;
		}
		s=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==1)
			{
				s++;
			}
		}
		if(s==0)
		{
			printf("No\n");
			continue;
		}
		if(s<n)
		{
			printf("Yes\n");
			continue;
		}
		if(x%2==1)
		{
			printf("Yes\n");
			continue;
		}
		printf("No\n");
	} 
	return 0;
}