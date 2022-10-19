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
	int t,n,x,y,las;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=1;
		las=-1;
		flag=true;
		for(int i=1;i<=n;i++)
		{
			y=read();
			if(y==1)
			{
				if(las==1)x+=5;
				else x+=1;
				las=1;
			}
			else
			{
				if(las==0)flag=false;
				las=0;
			}
		}
		if(flag==false)printf("-1\n");
		else printf("%d\n",x);
	}
	return 0;
}