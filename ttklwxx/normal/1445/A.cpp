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
int a[100004],b[100004];
int main()
{
	int t,n,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]+b[n+1-i]>x)
			{
				printf("No\n");
				flag=true;
				break;
			}
		}
		if(flag==false)printf("Yes\n");
	} 
	return 0;
}