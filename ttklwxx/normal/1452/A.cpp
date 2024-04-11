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
	int t,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		if(x==y)printf("%d\n",x+y);
		else printf("%d\n",2*max(x,y)-1);
	} 
	return 0;
}