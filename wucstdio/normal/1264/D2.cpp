#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n;
char s[1000005];
ll fact[1000005],inv[1000005],c1[1000005],c2[1000005];
int a[1000005],b[1000005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	int num=0;
	for(int i=1;i<=n;i++)
	  if(s[i]=='?')
	    num++;
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%MOD;
	inv[n]=quick_pow(fact[n],MOD-2);
	for(int i=n;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	for(int i=0;i<=num;i++)c1[i]=fact[num]*inv[i]%MOD*inv[num-i]%MOD;
	for(int i=0;i<num;i++)c2[i]=fact[num-1]*inv[i]%MOD*inv[num-1-i]%MOD;
	for(int i=num;i>=0;i--)
	{
		c1[i]=(c1[i]+c1[i+1])%MOD;
		c2[i]=(c2[i]+c2[i+1])%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')a[i]=a[i-1]+1;
		else a[i]=a[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(s[i]==')')b[i]=b[i+1]+1;
		else b[i]=b[i+1];
	}
	num=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')ans+=c1[max(a[i-1]+1-b[i]+num,0)];
		else if(s[i]=='?')ans+=c2[max(a[i-1]+1-b[i]+num,0)];
		if(s[i]=='?')num++;
	}
	printf("%lld\n",ans%MOD);
	return 0;
}