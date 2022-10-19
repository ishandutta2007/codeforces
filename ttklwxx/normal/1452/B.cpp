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
int a[200001];
signed main()
{
	int t,n,maxn,s;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		maxn=0;
		s=0;
		for(int i=1;i<=n;i++)a[i]=read(),s+=a[i],maxn=max(maxn,a[i]);
		if(maxn*(n-1)<=s)printf("%lld\n",(n-1-s%(n-1))%(n-1));
		else printf("%lld\n",maxn*(n-1)-s);
	} 
	return 0;
}