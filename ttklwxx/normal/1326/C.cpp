#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 998244353
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
int a[500001],pos[500001];
bool bi(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	int n,maxn=0,k,ans=1;
	long long tans=0;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)a[i]=read(),pos[i]=i;
	sort(pos+1,pos+n+1,bi);
	sort(pos+1,pos+k+1);
	tans=a[pos[1]];
	for(int i=2;i<=k;i++)
	{
		ans=1LL*ans*(pos[i]-pos[i-1]+mod)%mod;
		tans+=a[pos[i]];
	}
	printf("%lld %d\n",tans,ans);
	return 0;
}