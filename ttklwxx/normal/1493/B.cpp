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
int val(int x)
{
	if(x%10!=0&&x%10!=1&&x%10!=2&&x%10!=5&&x%10!=8)return 1000000000;
	if(x/10!=0&&x/10!=1&&x/10!=2&&x/10!=5&&x/10!=8)return 1000000000;
	int y=x/10,z=x%10;
	if(y==2)y=5;
	else if(y==5)y=2;
	if(z==2)z=5;
	else if(z==5)z=2;
	return z*10+y;
}
void sc(int x,int y)
{
	if(x<10)printf("0");
	printf("%d:",x);
	if(y<10)printf("0");
	printf("%d\n",y);
}
int main()
{
	int t,h,m,nx,ny,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		h=read();
		m=read();
		nx=read();
		ny=read();
		if(val(nx)<m&&val(ny)<h)
		{
			sc(nx,ny);
			continue;
		}
		while(1)
		{
			ny++;
			if(ny>=m)
			{
				ny=0;
				nx++;
				if(nx>=h)nx=0;
			}
			if(val(nx)<m&&val(ny)<h)
			{
				x=nx;
				y=ny;
				break;
			}
		}
		sc(x,y);
	}
	return 0;
}