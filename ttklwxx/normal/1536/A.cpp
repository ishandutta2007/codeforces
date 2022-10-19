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
int a[105];
int main()
{
	int t,n;
	bool flag1=false,flag2=false;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		flag1=false;
		flag2=false;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]>0)flag1=true;
			if(a[i]<0)flag2=true;
		}
		if(flag2==true)printf("NO\n");
		else
		{
			printf("Yes\n");
			printf("101\n");
			for(int i=0;i<=100;i++)printf("%d ",i);
			printf("\n");
		}
	} 
	return 0;
}