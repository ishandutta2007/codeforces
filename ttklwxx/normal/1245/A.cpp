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
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
int main()
{
	int t,a,b;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		if(gcd(a,b)==1)printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}