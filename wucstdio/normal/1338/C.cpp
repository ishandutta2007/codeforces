#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int x1[4]={0,1,2,3};
int x2[4]={0,2,3,1};
int x3[4]={0,3,1,2};
int t,res[75];
ll ask1(ll n)
{
	ll v=1;
	while(n>v)n-=v,v*=4;
	n--;
	for(int i=0;i<70;i++)
	{
		res[i]=n&1;
		n>>=1;
	}
	ll ans=0;
	for(int i=0;i<35;i++)ans+=(1ll<<(2*i))*x1[res[2*i+1]*2+res[2*i]];
	return ans+v;
}
ll ask2(ll n)
{
	ll v=1;
	while(n>v)n-=v,v*=4;
	n--;
	for(int i=0;i<70;i++)
	{
		res[i]=n&1;
		n>>=1;
	}
	ll ans=0;
	for(int i=0;i<35;i++)ans+=(1ll<<(2*i))*x2[res[2*i+1]*2+res[2*i]];
	return ans+v*2;
}
ll ask3(ll n)
{
	ll v=1;
	while(n>v)n-=v,v*=4;
	n--;
	for(int i=0;i<70;i++)
	{
		res[i]=n&1;
		n>>=1;
	}
	ll ans=0;
	for(int i=0;i<35;i++)ans+=(1ll<<(2*i))*x3[res[2*i+1]*2+res[2*i]];
	return ans+v*3;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n%3==1)printf("%lld\n",ask1(n/3+1));
		if(n%3==2)printf("%lld\n",ask2(n/3+1));
		if(n%3==0)printf("%lld\n",ask3(n/3));
	}
	return 0;
}