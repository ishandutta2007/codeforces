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
	int t,a,b,c,p;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		p=read();
		a=read();
		b=read();
		c=read();
		printf("%lld\n",min(min((a-p%a)%a,(b-p%b)%b),(c-p%c)%c));
	}
	return 0;
}