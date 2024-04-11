#include<iostream>
#include<cstdio>
#include<cmath>
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
int a,b,c;
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int t;
	t=read();
	for(int i=1;i<=t;i++)
	{
		a=read();
		b=read();
		c=read();
		if(a>b)swap(a,b);
		if(a>c)swap(a,c);
		if(b>c)swap(b,c);
		if(a<c)a++;
		if(c>a)c--;
		printf("%lld\n",2*c-2*a);
	}
	return 0;
}