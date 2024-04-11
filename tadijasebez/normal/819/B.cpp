#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
#define ll long long
const int N=2000050;
int a[N],b[N],ans;
ll sol;
int abs(int x){ return x>0?x:-x;}
ll min(ll a, ll b){ return a>b?b:a;}
int main()
{
	int n,i,p=0;
	ll sum=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		sum+=abs(a[i]-i);
		b[(a[i]-i+n)%n]++;
		if(a[i]<i) p++;
		else p--;
	}
	sol=sum;
	for(i=0;i<n-1;i++)
	{
		p+=b[i]*2-2;
		sum+=abs(a[n-i]-1)-abs(a[n-i]-n)+p+1;
		sol=min(sol,sum);
		if(sol==sum) ans=i+1;
	}
	printf("%lld %i\n",sol,ans);
	return 0;
}