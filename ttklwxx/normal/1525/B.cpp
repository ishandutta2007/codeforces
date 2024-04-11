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
int a[100005];
int main()
{
	int t,n;
	bool flag1;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		flag1=true;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]!=i)flag1=false;
		}
		if(flag1==true)printf("0\n");
		else if(a[1]==n&&a[n]==1)printf("3\n");
		else if(a[1]!=1&&a[n]!=n)printf("2\n"); 
		else printf("1\n");
	}
	return 0;
}