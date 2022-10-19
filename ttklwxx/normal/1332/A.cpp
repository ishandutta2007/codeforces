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
	int a,b,c,d,x,y,x1,y1,x2,y2;
	int t;
	t=read();
	for(int i=1;i<=t;i++)
	{
		a=read();
		b=read();
		c=read();
		d=read();
		x=read();
		y=read();
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		if(x==x1&&x==x2)
		{
			if(a!=0||b!=0)
			{
				printf("No\n");
				continue;
			}
		}
		if(y==y1&&y==y2)
		{
			if(c!=0||d!=0)
			{
				printf("No\n");
				continue;
			}
		}
		if(x1<=x+b-a&&x+b-a<=x2&&y1<=y+d-c&&y+d-c<=y2)
		{
			printf("Yes\n");
			continue;
		}
		printf("No\n");
	} 
	return 0;
}