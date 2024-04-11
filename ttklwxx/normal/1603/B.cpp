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
	int t,x,y,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		if(x==y)printf("%lld\n",x);
		else if(x>y)printf("%lld\n",x+y);
		else
		{
			k=(y/x+1)/2;
			printf("%lld\n",(y+(2*k-1)*x)/2);
		}
	}
	return 0;
}