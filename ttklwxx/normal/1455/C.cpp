#include<iostream>
#include<cstdio>
#include<cstring>
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
	int t,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		printf("%d %d\n",x-1,y);
	}
	return 0;
}