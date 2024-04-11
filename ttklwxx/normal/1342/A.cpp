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
	int t,x,y,a,b;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		a=read();
		b=read();
		if(x>y)swap(x,y);
		printf("%lld\n",min(a*(y-x)+b*x,a*(x+y)));
	}
	return 0;
}