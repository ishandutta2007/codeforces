#include <bits/stdc++.h>
#define modp 1000000007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int a[200007];
int pre[200007],inv[200007],r[200007],r1[200007];
long long ans=0;
long long power(long long a,long long b)
{
	long long ans=1,now=a,left=b;
	while (left>0)
	{
		if (left%2==1) ans=(1LL*ans*now)%modp;
		left/=2;
		now=(1LL*now*now)%modp;
	}
	return ans;
}
long long calc(int a,int b)
{
	long long res=pre[a];
	res=(1LL*res*inv[b])%modp;
	res=(1LL*res*inv[a-b])%modp;
	return res;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	memset(pre,0,sizeof(pre));
	pre[0]=1;
	for (int i=1;i<=n;i++) pre[i]=(1LL*pre[i-1]*i)%modp;
	inv[n]=power(pre[n],modp-2);
	for (int i=n-1;i>=0;i--) inv[i]=(1LL*inv[i+1]*(i+1))%modp;
	memset(r,0,sizeof(r));
	int k=n;
	while (k%4!=1) k--;
	int k1=(k-1)/2;
	for (int i=1;i<=k;i++)
		if (i%2==0) r[i]=0; else r[i]=calc(k1,(i-1)/2);
	while (k<n)
	{
		++k;
		if (k%4==2)
		{
			r1[1]=r[1];
			for (int i=2;i<=k;i++)
				r1[i]=(r[i]+r[i-1])%modp;
			for (int i=1;i<=k;i++)
				r[i]=r1[i];
		} else if (k%4==3)
		{
			int flag=1;
			r1[1]=r[1];
			for (int i=2;i<=k;i++)
			{
				if (flag==1) r1[i]=(r[i]+r[i-1])%modp;
				else r1[i]=(r[i]-r[i-1]+modp)%modp;
				flag=1-flag;
			}
			for (int i=1;i<=k;i++)
				r[i]=r1[i];
		} else if (k%4==0)
		{
			int flag=0;
			r1[1]=r[1];
			for (int i=2;i<=k;i++)
			{
				if (flag==1) r1[i]=(r[i]+r[i-1])%modp;
				else r1[i]=(r[i-1]-r[i]+modp)%modp;
				flag=1-flag;
			}
			for (int i=1;i<=k;i++)
				r[i]=r1[i];
		}
	}
	for (int i=1;i<=n;i++)
		ans=(ans+1LL*a[i]*r[i]%modp)%modp;
	printf("%I64d\n",ans);
	return 0;
}