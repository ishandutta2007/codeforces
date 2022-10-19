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
	int t,x1,x2,y1,y2;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		if(x1==x2)printf("%d\n",abs(y2-y1));
		else if(y1==y2)printf("%d\n",abs(x2-x1));
		else printf("%d\n",abs(x2-x1)+abs(y1-y2)+2);
	} 
	return 0;
}