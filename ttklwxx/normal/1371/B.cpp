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
	int t,n,k,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		x=min(n-1,k);
		printf("%lld\n",(k>=n)+1LL*x*(x+1)/2);
	} 
	return 0;
}