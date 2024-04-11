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
int main()
{
	int t,a,b,c;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		c=read();
		if(a<c)printf("1 ");
		else printf("-1 ");
		if(1LL*a*b>c)printf("%d\n",b);
		else printf("-1\n");
	}
	return 0;
}