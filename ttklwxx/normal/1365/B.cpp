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
int a[1001],b[1001];
int main()
{
	int t,n,x;
	bool flag=false;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		x=0;
		for(int i=1;i<=n;i++)if(b[i]==0)x++;
		if(x==0||x==n)
		{
			flag=false;
			for(int i=1;i<=n-1;i++)if(a[i]>a[i+1])
			{
				printf("No\n");
				flag=true;
				break;
			}
			if(flag==false)printf("Yes\n");
		}
		else printf("Yes\n");
	} 
	return 0;
}