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
int a[200005];
int main()
{
	int t,n,het;
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
		het-=n;
		if(het==0)
		{
			printf("0\n");
			continue;
		}
		if(het<0)
		{
			printf("1\n");
			continue;
		}
		printf("%d\n",het);
	} 
	return 0;
}