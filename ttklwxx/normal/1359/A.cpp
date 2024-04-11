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
	int t,n,m,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		if(m<=n/k)
		{
			printf("%d\n",m);
			continue;
		}
		else
		{
			printf("%d\n",n/k-(m-n/k-1)/(k-1)-1);
		}
	} 
	return 0;
}