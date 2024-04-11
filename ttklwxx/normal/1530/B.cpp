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
	int t,h,w;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		h=read();
		w=read();
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				if(i==1&&j%2==1)printf("1");
				else if(i==h&&j%2==1&&j>(h-1)%2&&j<=w-(h-1)%2*2)printf("1");
				else if(j==1&&i%2==1)printf("1");
				else if(j==w&&i%2==1&&i>(w-1)%2&&i<=h-(w-1)%2*2)printf("1");
				else if(h%2==0&&w%2==0&&i==h&&j==w)printf("1");
				else printf("0");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}