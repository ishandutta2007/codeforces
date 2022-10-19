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
	int t,n,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
	    m=read();
	    if(n%2==1&&m%2==1)
	    {
	    	for(int i=1;i<=n;i++)
	    	{
	    		for(int j=1;j<=m;j++)
	    		{
	    			if((i+j)%2==0)printf("B");
	    			else printf("W");
				}
				printf("\n");
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(i==1&&j==1)
					{
						printf("B");
						continue;
					}
					if((i+j)%2==0)printf("W");
	    			else printf("B");
				}
				printf("\n");
			}
		}
	} 
	return 0;
}