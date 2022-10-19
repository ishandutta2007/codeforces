#include<iostream>
#include<cstdio>
#include<cmath>
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
int a[100001],la[100001];
int b[100001],lb[100001];
int za[100001],zb[100001];
signed main()
{
	int n,m,k;
	long long ans=0;
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==1)la[i]=la[i-1]+1;
		else la[i]=0;
		za[la[i]]++;
	} 
	for(int i=1;i<=m;i++)
	{
		b[i]=read();
		if(b[i]==1)lb[i]=lb[i-1]+1;
		else lb[i]=0;
		zb[lb[i]]++;
	}
	for(int i=n-1;i>=1;i--)za[i]+=za[i+1];
	for(int i=m-1;i>=1;i--)zb[i]+=zb[i+1];
	for(int i=1;i<=sqrt(k);i++)
	{
		if(k%i!=0)continue;
		if(i<=n&&k/i<=m)ans+=za[i]*zb[k/i];
		if(i!=k/i&&k/i<=n&&i<=m)ans+=za[k/i]*zb[i];
	}
	printf("%lld\n",ans);
	return 0;
}