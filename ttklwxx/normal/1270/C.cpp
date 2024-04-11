#include<iostream>
#include<cstdio>
#define int long long
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
signed main()
{
	int t,n,het=0,yht=0,x;
	t=read();
	for(int sth=1;sth<=t;sth++)
	{
		n=read();
		het=0;
		yht=0;
		for(int i=1;i<=n;i++)
		{
			x=read();
			het+=x;
			yht^=x;
		}
		if(het%2==0)
		{
			het+=(1LL<<50);
			yht^=(1LL<<50);
			printf("3\n%lld %lld %lld\n",1LL<<50,(2*yht-het)/2,(2*yht-het)/2);
		}
		else
		{
			het+=(1LL<<50)+1;
			yht^=(1LL<<50)+1;
			printf("3\n%lld %lld %lld\n",(1LL<<50)+1,(2*yht-het)/2,(2*yht-het)/2);
		}
	}
	return 0;
}