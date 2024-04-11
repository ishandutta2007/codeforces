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
	int t,n,k,sth,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		sth=0;
		for(int i=0;i<=n-1;i++)
		{
			printf("%d\n",sth^i);
			sth=i;
			fflush(stdout);
			ans=read();
			if(ans==1)break;
		}
	}
	return 0;
}