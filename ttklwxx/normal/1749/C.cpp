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
int a[105],sl[105];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=100;i++)sl[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			sl[a[i]]++;
		}
		for(int i=2;i<=100;i++)sl[i]+=sl[i-1];
		for(int i=n;i>=0;i--)
		{
			bool flag=true;
			for(int j=1;j<=i;j++)
			{
				if(sl[j]<i-1+j)
				{
					flag=false;
					break;
				}
			}
			if(flag==true)
			{
				printf("%d\n",i);
				break;
			}
		}
	} 
}