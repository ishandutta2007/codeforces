#include<bits/stdc++.h>
using namespace std;
int ok(long long n)
{
	long long s=0,m=n;
	while(m)
	{
		s+=m%10;
		m/=10;
	}
	return __gcd(s,n)>1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		while(!ok(n))
			n++;
		printf("%lld\n",n);
	}
	return 0;
}