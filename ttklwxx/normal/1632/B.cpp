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
char s[100005];
int main()
{
	int t,n,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read()-1;
		x=1;
		while(x*2<=n)x*=2;
		for(int i=x-1;i>=0;i--)printf("%d ",i);
		for(int i=x;i<=n;i++)printf("%d ",i);
		printf("\n");
	}
	return 0;
}