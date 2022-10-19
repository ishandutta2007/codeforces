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
int jc[200005],njc[200005];
inline int ksm(int n,int k)
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
inline int c(int m,int n)
{
	if(n<0||n>m)return 0;
	return 1LL*jc[m]*njc[n]%mod*njc[m-n]%mod;
}
inline int nc(int m,int n)
{
	if(n<0||n>m)return 0;
	return 1LL*njc[m]*jc[n]%mod*jc[m-n]%mod;
}
int main()
{
	int t,n,k,ans;
	t=read();
	jc[0]=1;
	for(int i=1;i<=200000;i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[200000]=ksm(jc[200000],mod-2);
	for(int i=199999;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		ans=0;
		for(int i=0;i<=n;i++)
		{
			if(n-(k-1)*(i-1)<0)break;
			ans=(ans+1LL*c(n-(k-1)*(i-1),i)*nc(n,i)%mod)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}