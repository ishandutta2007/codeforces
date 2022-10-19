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
	int t,n,a,b,c,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		c=read();
		x=(a+2*b+3*c);
		if(a>=1&&b>=1)
		{
			if(x%2==0)printf("0\n");
			else printf("1\n");
		}
		else if(a==0)
		{
			if(b>=2)
			{
				if(x%2==0)printf("0\n");
				else printf("1\n");
			}
			else if(b==1)
			{
				if(c%2==0)printf("2\n");
				else printf("1\n");
			}
			else
			{
				if(c%2==0)printf("0\n");
				else printf("3\n");
			}
		}
		else if(b==0)
		{
			if(a==1)
			{
				if(c%2==0)printf("1\n");
				else printf("2\n");
			}
			else
			{
				if(x%2==0)printf("0\n");
				else printf("1\n");
			}
		}
	}
	return 0;
}