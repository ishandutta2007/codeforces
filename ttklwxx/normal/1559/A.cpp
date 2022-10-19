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
int main()
{
	int t,ans,x,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=2147483647;
		for(int i=1;i<=n;i++)
		{
			x=read();
			ans=(ans&x);
		}
		printf("%d\n",ans);
	} 
	return 0;
}