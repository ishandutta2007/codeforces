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
int a[114514];
int main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<=n-1;i++)
		{
			if(k<=a[i])
			{
				a[i]-=k;
				a[n]+=k;
				break;
			}
			a[n]+=a[i];
			k-=a[i];
			a[i]=0;
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	} 
	return 0;
}