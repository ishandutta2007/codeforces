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
int a[100005];
int main()
{
	int t,n,het=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		het=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			het+=a[i];
		}
		if(het%n==0)printf("0\n");
		else printf("1\n");
	} 
	return 0;
}