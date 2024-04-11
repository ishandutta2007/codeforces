#include<iostream>
#include<cstdio>
#define mod 1000000007
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
	int n,ans;
	n=read();
	int sth=1,x=1;
	for(int i=2;i<=n;i++)sth=1LL*i*sth%mod;
	for(int i=1;i<=n-1;i++)x=1LL*x*2%mod;
	printf("%d\n",(sth-x+mod)%mod);
	return 0;
}