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
int a[200001],b[200001];
int main()
{
	bool flag1,flagf1,flag;
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		flag1=false;
		flagf1=false;
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(b[i]>a[i]&&flag1==false)
			{
				printf("NO\n");
				flag=true;
				break;
			}
			if(b[i]<a[i]&&flagf1==false)
			{
				printf("NO\n");
				flag=true;
				break;
			}
			if(a[i]==1)flag1=true;
			else if(a[i]==-1)flagf1=true;
		}
		if(flag==false)printf("YES\n");
	}
	return 0;
}