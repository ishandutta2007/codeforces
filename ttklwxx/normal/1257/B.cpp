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
    int t,x,y;
	t=read();
	for(int i=1;i<=t;i++)
	{
		x=read();
		y=read();
		if(x>=4)
		{
			printf("Yes\n");
		}
		else if(x==3)
		{
			if(y<=3)printf("Yes\n");
			else printf("No\n");
		}
		else if(x==2)
		{
			if(y<=3)printf("Yes\n");
			else printf("No\n");
		}
		else
		{
			if(y==1)printf("Yes\n");
			else printf("No\n");
		}
	} 
    return 0;
}