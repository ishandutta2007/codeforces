#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int ans[200001];
int main()
{
	int a,b,c,d,a1,b1,c1,d1;
	bool flag;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a1=a;
	b1=b;
	c1=c;
	d1=d;
	if(a1+c1>=b1+d1)
	{
		if(a1+c1-b1-d1>1)
		{
			printf("NO\n");
			return 0;
		}
		for(int i=1;i<=a+b+c+d;i++)
		{
			if(i%2==1)
			{
			if(a1>=1)
			{
				ans[i]=0;
				a1--;
			}
			else
			{
				ans[i]=2;
				c1--;
			}
		    }
		    else
		    {
		    if(b1>=1)
			{
				ans[i]=1;
				b1--;
			}
			else
			{
				ans[i]=3;
				d1--;
			}	
			}
		}
		for(int i=1;i<=a+b+c+d-1;i++)if(abs(ans[i]-ans[i+1])!=1)
		{
			printf("NO\n");
			exit(0);
		}
		printf("YES\n");
		for(int i=1;i<=a+b+c+d;i++)printf("%d ",ans[i]);
		return 0;
	}
	if(b1+d1>a1+c1)
	{
		if(b1+d1-a1-c1>1)
		{
			printf("NO\n");
			return 0;
		}
		for(int i=1;i<=a+b+c+d;i++)
		{
			if(i%2==0)
			{
			if(a1>=1)
			{
				ans[i]=0;
				a1--;
			}
			else
			{
				ans[i]=2;
				c1--;
			}
		    }
		    else
		    {
		    if(b1>=1)
			{
				ans[i]=1;
				b1--;
			}
			else
			{
				ans[i]=3;
				d1--;
			}	
			}
		}
		for(int i=1;i<=a+b+c+d-1;i++)if(abs(ans[i]-ans[i+1])!=1)
		{
			printf("NO\n");
			exit(0);
		}
		printf("YES\n");
		for(int i=1;i<=a+b+c+d;i++)printf("%d ",ans[i]);
		return 0;
	}
}