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
int a[200005];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		flag=true;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				flag=false;
				break;
			}
		} 
		if(flag==false)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}