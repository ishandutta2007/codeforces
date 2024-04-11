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
int gcd(int m,int n)
{
	if(m==0)return n;
	if(n==0)return m;
	while(m^=n^=m^=n%=m);
	return n;
} 
signed main()
{
	int t,m,d,w,sth,x;
	t=read();
	for(int i=1;i<=t;i++)
	{
		m=read();
		d=read();
		w=read();
		sth=gcd(d-1,w);
		w/=sth;
		x=min(m,d);
		printf("%lld\n",(x%w)*(x/w+1)*(x/w)/2+(w-x%w)*(x/w)*(x/w-1)/2);
	}
	return 0;
}