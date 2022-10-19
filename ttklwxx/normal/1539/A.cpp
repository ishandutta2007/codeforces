#include<iostream>
#include<cstdio>
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
	int t,n,x,k;
	k=read();
	for(int greg=1;greg<=k;greg++)
	{
		n=read();
		x=read();
		t=read();
		if(n>=t/x)printf("%lld\n",n*((t/x))-(t/x)*(t/x+1)/2);
		else printf("%lld\n",n*(n-1)/2); 
	}
	return 0;
}