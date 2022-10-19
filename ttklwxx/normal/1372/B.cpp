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
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		flag=false;
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				printf("%d %d\n",n/i,n-n/i);
				flag=true;
				break;
			}
		}
		if(flag==false)printf("%d %d\n",1,n-1);
	}
	return 0;
}