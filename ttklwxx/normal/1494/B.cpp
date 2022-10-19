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
	int t,n,u,r,d,l,sth;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		u=read();
		r=read();
		d=read();
		l=read();
		if(n==1)
		{
			if(u==r&&r==d&&d==l)printf("YES\n");
			else printf("NO\n");
			continue;
		}
		flag=false;
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				for(int k=0;k<=1;k++)
				{
					for(int jk=0;jk<=1;jk++)
					{
						if(0>u-i-j||u-i-j>n-2)continue;
						if(0>r-k-j||r-k-j>n-2)continue;
						if(0>d-k-jk||d-k-jk>n-2)continue;
						if(0>l-i-jk||l-jk-i>n-2)continue;
						flag=true;
						break;
					}
				}
			}
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}