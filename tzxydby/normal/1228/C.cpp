#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
long long x,n;
long long qp(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
long long solve(long long p)
{
	long long k=p,sum=1;
	while(1)
	{
		sum=qp(p,n/k)*sum%mod;
		if(n/k<p)
			break;
		k*=p;
	}
	return sum;
} 
int is_p(long long p)
{
	for(long long i=2;i*i<=p;i++)
		if(p%i==0)
			return 0;
	return 1;
}
main()
{
	cin>>x>>n;
	long long ans=1;
	for(long long i=2;i*i<=x;i++)
	{
		if(x%i)
			continue;
		if(is_p(i))
			ans=(ans*solve(i))%mod;
		if(i*i!=x&&is_p(x/i))
			ans=(ans*solve(x/i))%mod;
	}
	if(is_p(x))
		ans=(ans*solve(x))%mod;
	cout<<ans<<endl; 
	return 0;
}