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
int a[100001];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		for(int j=1;j<=n;j++)a[j]=read();
		if(n==1&&a[1]%2==1)
		{
			printf("-1\n");
			continue;
		}
		flag=false;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%2==0)
			{
				printf("1\n%d\n",j);
				flag=true;
				break;
			} 
		}
		if(flag==false)
		{
			printf("2\n1 2\n");
		}
	} 
	return 0;
}