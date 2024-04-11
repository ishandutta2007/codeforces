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
	bool flag=false;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		flag=false;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]<=a[i+1])
			{
				flag=true;
				break;
			} 
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}