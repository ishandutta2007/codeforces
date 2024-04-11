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
int b[800004];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		for(int i=1;i<=7;i++)b[i]=read();
		printf("%d %d %d\n",b[1],b[2],b[7]-b[1]-b[2]);
	}
	return 0;
}