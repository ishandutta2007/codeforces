#include<iostream>
#include<cstdio>
#include<algorithm>
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
int x[501],y[501];
int main()
{
	int t,n,k,ans=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
			y[i]=read();
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			flag=false;
			for(int j=1;j<=n;j++)
			{
				if(abs(x[i]-x[j])+abs(y[i]-y[j])>k)
				{
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				printf("1\n");
				break;
			}
		}
		if(flag==true)printf("-1\n");
	} 
	return 0;
}