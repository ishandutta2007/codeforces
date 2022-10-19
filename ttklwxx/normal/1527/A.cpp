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
	int t,n,k,tans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=30;i>=0;i--)
		{
			if((1<<i)&n)
			{
				k=(1<<i)-1;
				break;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}