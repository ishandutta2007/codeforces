#include<iostream>
#include<cstdio>
#include<cmath>
#define mod 1000000007
#define int long long
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
signed main()
{
	int t,x;
	t=read();
	for(int i=1;i<=t;i++)
	{
		x=read();
		printf("%d %d\n",1,x-1);
	}
}