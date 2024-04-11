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
	int t,n,minn,msl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		minn=1000000000;
		msl=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]<minn)
			{
				minn=a[i];
				msl=1;
			}
			else if(a[i]==minn)msl++;
		}
		printf("%d\n",n-msl);
	}
	return 0;
}