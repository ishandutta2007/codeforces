#include<iostream>
#include<cstdio>
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
int jc[200005],njc[200005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		n=1LL*n*n%mod;
		k>>=1;
	}
	return ans;
}
int main()
{
	int n,m,ans=0;
	n=read();
	m=read();
	jc[0]=1;
	for(int i=1;i<=m;i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[m]=ksm(jc[m],mod-2);
	for(int i=m-1;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	for(int k=n-1;k<=m;k++)ans=(ans+1LL*jc[k-1]*njc[n-3]%mod*njc[k-n+1]%mod)%mod;
	printf("%d\n",1LL*ans*ksm(2,n-3)%mod);
	return 0;
}