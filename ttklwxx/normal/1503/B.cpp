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
	int n,a;
	n=read();
	int x1,y1,x2,y2,sl1,sl2;
	x1=1;
	y1=1;
	x2=1;
	y2=2;
	sl1=(n*n+1)/2;
	sl2=n*n/2;
	for(int i=1;i<=n*n;i++)
	{
		a=read();
		if(sl1>0&&sl2>0)
		{
			if(a!=1)
			{
				printf("%d %d %d\n",1,x1,y1);
				y1+=2;
				if(y1>n)
				{
					x1++;
					if(y1%2==0)y1=1;
					else y1=2;
				}
				sl1--;
			}
			else
			{
				printf("%d %d %d\n",2,x2,y2);
				y2+=2;
				if(y2>n)
				{
					x2++;
					if(y2%2==0)y2=1;
					else y2=2;
				}
				sl2--;
			}
		}
		else if(sl1==0)
		{
			if(a==2)
			{
				printf("3 %d %d\n",x2,y2);
				y2+=2;
				if(y2>n)
				{
					x2++;
					if(y2%2==0)y2=1;
					else y2=2;
				}
				sl2--;
			}
			else
			{
				printf("%d %d %d\n",2,x2,y2);
				y2+=2;
				if(y2>n)
				{
					x2++;
					if(y2%2==0)y2=1;
					else y2=2;
				}
				sl2--;
			}
		}
		else
		{
			if(a==1)
			{
				printf("3 %d %d\n",x1,y1);
				y1+=2;
				if(y1>n)
				{
					x1++;
					if(y1%2==0)y1=1;
					else y1=2;
				}
				sl2--;
			}
			else
			{
				printf("%d %d %d\n",1,x1,y1);
				y1+=2;
				if(y1>n)
				{
					x1++;
					if(y1%2==0)y1=1;
					else y1=2;
				}
				sl1--;
			}
		}
		fflush(stdout);
	}
	return 0;
}