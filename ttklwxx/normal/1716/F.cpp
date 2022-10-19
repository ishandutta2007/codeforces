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
int f[2005][2005],jc[2005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
int main()
{
	f[1][1]=1;
	for(int i=2;i<=2000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=(f[i-1][j-1]+1LL*j*f[i-1][j]%mod)%mod;
			//if(i==8)printf("%d %d %d\n",i,j,f[i][j]);
		}
	}
	jc[0]=1;
	for(int i=1;i<=2000;i++)jc[i]=1LL*jc[i-1]*i%mod;
	int t,n,m,k,now,js,os,cj,ans,cm,fcj;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		if(m==1)
		{
			printf("%d\n",ksm(n,k));
			continue;
		}
		js=(m+1)/2;
		os=m/2;
		cj=1LL*js*ksm(os,mod-2)%mod;
		fcj=ksm(cj+1,mod-2);
		cm=ksm(cj+1,n);
		now=n;
		ans=0;
		for(int i=1;i<=min(n,k);i++)
		{
			now=1LL*now*cj%mod;
			cm=1LL*cm*fcj%mod;
			//printf("%d %d %d\n",now,cm,1LL*now*cm%mod*f[k][i]%mod);
			ans=(ans+1LL*now*cm%mod*f[k][i]%mod)%mod;
			now=1LL*now*(n-i)%mod; 
		}
		ans=1LL*ans*ksm(os,n)%mod;
		printf("%d\n",ans);
	}
	return 0;
}