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
	int t,a,b,n,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		n=read();
		m=read();
		if(n+m>a+b)printf("No\n");
		else
		{
			if(min(a,b)<m)printf("No\n");
			else printf("Yes\n");
		}
	} 
	return 0;
}