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
	int t,r,b,d;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		r=read();
		b=read();
		d=read();
		if((r-1)/b<=d&&(b-1)/r<=d)
		{
			printf("YEs\n");
		}
		else printf("No\n");
	}
	return 0;
}