#include<iostream>
#include<cstdio>
#include<cmath>
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
	int t,x1,p1,x2,p2;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x1=read();
		p1=read();
		x2=read();
		p2=read();
		if(fabs(log(x1)/log(10)+p1-log(x2)/log(10)-p2)<=1e-12)printf("=");
		else if(log(x1)/log(10)+p1<log(x2)/log(10)+p2)printf("<");
		else printf(">");
		printf("\n");
	} 
	return 0;
}