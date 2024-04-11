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
int jc[400005],njc[400005];
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
inline int c(int m,int n)
{
	if(n<0||n>m)return 0;
	return 1LL*jc[m]*njc[n]%mod*njc[m-n]%mod;
}
int main()
{
	jc[0]=1;
	for(int i=1;i<=400000;i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[400000]=ksm(jc[400000],mod-2);
	for(int i=399999;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	int t,n,l,r,ans=0,sth,lg,rg;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		l=read();
		r=read();
		sth=min(1-l,r-n);
		ans=1LL*sth*c(n,n/2)%mod;
		if(n&1)ans=(ans+1LL*sth*c(n,n/2+1))%mod;
		for(int k=sth+1;true;k++)
		{
			lg=max(1,l+k);
			rg=min(n,r-k);
			if(rg+1<lg)break;
			ans=(ans+c(rg+1-lg,n/2-lg+1))%mod;
			if(n&1)ans=(ans+c(rg+1-lg,n/2-lg+2))%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}