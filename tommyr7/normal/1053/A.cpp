#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long gcd(long long a,long long b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	long long s=(2LL*n*m);
	if (s%k!=0) printf("NO\n");
	else
	{
		printf("YES\n");
		if (k%2==0)
		{
			k/=2;
			long long t=gcd(n,k);
			n/=t,k/=t;
			m/=k;
			printf("%d %d\n",0,0);
			printf("%d %lld\n",0,m);
			printf("%lld %d\n",n,0);
		} else
		{
			long long n1=n,m1=m;
			long long t=gcd(n,k);
			n/=t,k/=t;
			m/=k;
			if (2LL*n<=n1) n=2LL*n; else m=2LL*m;
			printf("%d %d\n",0,0);
			printf("%d %lld\n",0,m);
			printf("%lld %d\n",n,0);
		}
	}
	return 0;
}