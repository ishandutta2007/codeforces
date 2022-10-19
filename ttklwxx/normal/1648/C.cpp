#include<iostream>
#include<cstdio>
#define int long long
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
int s[400005],t[400005];
int sl[400005];
int jc[400005],njc[400005];
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
int f[400005],n,m;
void insert(int k,int x)
{
	while(k<=200000)
	{
		f[k]=(f[k]+x)%mod;
		k+=((k)&(-k));
	}
}
int query(int k)
{
	int ans=0;
	while(k>=1)
	{
		ans=(ans+f[k])%mod;
		k-=((k)&(-k));
	}
	return ans;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		s[i]=read();
		sl[s[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		t[i]=read();
	}
	jc[0]=1;
	for(int i=1;i<=max(n,m);i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[max(n,m)]=ksm(jc[max(n,m)],mod-2);
	for(int i=max(n,m)-1;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	int ans=1;
	for(int i=1;i<=200000;i++)
	{
		ans=1LL*ans*njc[sl[i]]%mod;
		insert(i,sl[i]);
	}
	int tans=0,now;
	for(int i=1;i<=min(n,m);i++)
	{
		now=1LL*query(t[i]-1)*ans%mod*jc[n-i]%mod;
		//printf("%lld %lld %lld\n",query(t[i]-1),ans,sl[t[i]]);
		//printf("%lld\n",now);
		tans=(tans+now)%mod;
		ans=1LL*ans*sl[t[i]]%mod;
		insert(t[i],mod-1);
		sl[t[i]]--;
		if(sl[t[i]]<0)break;
	}
	if(m>n)
	{
		bool flag=true;
		for(int i=1;i<=200000;i++)if(sl[i]!=0)
		{
			flag=false;
			break;
		}
		if(flag==true)tans=(tans+1)%mod;
	}
	printf("%lld\n",tans);
	return 0;
}