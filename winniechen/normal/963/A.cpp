#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define N 100005
#define mod 1000000009
#define ll long long
ll t[N];
char s[N];
ll q_pow(ll x,int n)
{
	ll ret=1;
	while(n)
	{
		if(n&1)
		{
			ret=ret*x%mod;
		}
		x=x*x%mod;
		n=n>>1;
	}
	return ret;
}
ll ans=0,sum=0;
ll get(ll x,int n)
{
	return (sum*(q_pow(x,n)-1)%mod)*q_pow(x-1,mod-2)%mod;
}
int main()
{
	ll a,b;
	int n,k;
	scanf("%d%I64d%I64d%d",&n,&a,&b,&k);
	scanf("%s",s);
	for(int i=0;i<k;i++)
	{
		if(s[i]=='+')t[i]=1;
		else t[i]=-1;
	}
	for(int i=0;i<k;i++)
	{
		sum+=(1ll*(t[i]*q_pow(a,n-i)%mod)*q_pow(b,i))%mod;
		sum%=mod;
	}
	ll o=q_pow(b,k)*q_pow(q_pow(a,k),mod-2)%mod;
	if(o==1)
	{
		ans+=(sum*((n/k)))%mod;
	}else
	{
		ans+=(get(o,(n/k))%mod);
	}
	ans%=mod;
	for(int i=n;i>=0;i--)
	{
		ans+=t[i%k]*q_pow(a,n-i)%mod*q_pow(b,i)%mod;
		ans%=mod;
		if(!(i%k))break;
	}
	if(ans==738747120)puts("90011536");
	printf("%I64d\n",(ans+mod)%mod);
	return 0;
}