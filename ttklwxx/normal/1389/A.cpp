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
	int t,l,r;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		l=read();
		r=read();
		if(2*l<=r)
		{
			printf("%d %d\n",l,2*l);
		}
		else
		{
			printf("-1 -1\n");
		}
	}
	return 0;
}