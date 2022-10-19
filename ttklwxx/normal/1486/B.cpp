#include<iostream>
#include<cstdio>
#include<algorithm>
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
int x[100005],y[100005];
signed main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		printf("%lld\n",(y[(n+2)/2]-y[(n+1)/2]+1)*(x[(n+2)/2]-x[(n+1)/2]+1));
	}
	return 0;
}