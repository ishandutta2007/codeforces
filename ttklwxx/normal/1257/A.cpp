#include<iostream>
#include<cstdio>
#include<cmath>
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
    int t,n,a,b,x;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		x=read();
		a=read();
		b=read();
		printf("%d\n",min(abs(a-b)+x,n-1));
	} 
    return 0;
}