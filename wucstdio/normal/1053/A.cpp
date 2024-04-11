#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,m,k;
ll gcd(ll a,ll b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if(n*m*2%k!=0)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("0 0\n");
	ll N=n,M=m;
	ll d=gcd(n,k);
	n/=d;
	k/=d;
	d=gcd(m,k);
	m/=d;
	k/=d;
	if(k==1)
	{
		if(n*2<=N)n*=2;
		else m*=2;
	}
	printf("%I64d 0\n",n);
	printf("0 %I64d\n",m);
	return 0;
}