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
char s[10001];
int main()
{
	int t,n,a,b,c,ta,tb,tc;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
    	n=read();
    	a=read();
    	b=read();
    	c=read();
    	scanf("%s",s+1);
    	ta=0;
    	tb=0;
    	tc=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(s[i]=='R')ta++;
    		else if(s[i]=='P')tb++;
    		else tc++;
		}
		if(min(a,tc)+min(b,ta)+min(c,tb)<(n+1)/2)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R')
			{
				if(b>0)
				{
					b--;
					ta--;
					printf("P");
				}
				else
				{
					if(a>tc)
					{
					    a--;
					    printf("R");
					}
					else
					{
						c--;
						printf("S");
					}
				}
			}
			else if(s[i]=='P')
			{
				if(c>0)
				{
					c--;
					tb--;
					printf("S");
				}
				else
				{
					if(a>tc)
					{
					    a--;
					    printf("R");
					}
					else
					{
						b--;
						printf("P");
					}
				}
			}
			else
			{
				if(a>0)
				{
					a--;
					tc--;
					printf("R");
				}
				else
				{
					if(b>ta)
					{
					    b--;
					    printf("P");
					}
					else
					{
						c--;
						printf("S");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}