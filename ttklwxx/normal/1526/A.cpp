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
int a[200005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=2*n;i++)a[i]=read();
		sort(a+1,a+2*n+1);
		for(int i=1;i<=n;i++)printf("%d %d ",a[i],a[2*n+1-i]);
		printf("\n");
	}
	return 0;
}