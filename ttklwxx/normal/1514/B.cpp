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
int jc[200005],njc[200005];
int zh(int n,int m)
{
	if(n<m)return 0;
	return 1LL*jc[n]*njc[m]%mod*njc[n-m]%mod;
}
int main()
{
	jc[0]=1;
	for(int i=1;i<=100000;i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[100000]=ksm(jc[100000],mod-2);
	for(int i=99999;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		printf("%d\n",1LL*ksm(n,k)%mod);
	}
	return 0;
}