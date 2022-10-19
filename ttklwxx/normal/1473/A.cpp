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
	int t,n,d;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		if(a[n]<=d)printf("Yes\n");
		else if(a[1]+a[2]<=d)printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}