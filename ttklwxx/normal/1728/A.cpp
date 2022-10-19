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
int a[1005];
int main()
{
	int t,n,maxn,mpos;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]>maxn)
			{
				maxn=a[i];
				mpos=i;
			}
		}
		printf("%d\n",mpos);
	}
	return 0;
}