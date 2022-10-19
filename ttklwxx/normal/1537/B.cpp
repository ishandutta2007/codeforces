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
int main()
{
	int t,n,m,i,j,ax1,ax2,ay1,ay2;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		i=read();
		j=read();
		printf("%d %d %d %d\n",1,1,n,m);
	} 
	return 0;
}