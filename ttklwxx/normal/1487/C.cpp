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
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if((j-i)%2==0)printf("1 ");
					else printf("-1 ");
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if((i-1)/2==(j-1)/2)
					{
						printf("0 ");
						continue;
					}
					if((j-i)%2==0)printf("1 ");
					else printf("-1 ");
		    	}
			}
		}
		printf("\n");
	}
	return 0;
}