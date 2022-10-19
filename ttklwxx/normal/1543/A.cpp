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
	int t,a,b,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		if(a>b)swap(a,b);
		if(a!=b)
		{
			x=b/(b-a);
			printf("%lld %lld\n",b-a,min(b-x*(b-a),(x+1)*(b-a)-b));
		}
		else printf("%d %d\n",0,0);
	}
	return 0;
}