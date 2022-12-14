#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define ll long long
ll n;
int check(ll x)
{
	ll sum=n,ans1=0;
	while(sum>=0)
	{
		ans1+=min(sum,x);sum-=x;
		sum-=sum/10;
	}
	return ans1*2<n;
}
int main()
{
	scanf("%lld",&n);
	ll l=1,r=1000000000000000001ll;
	while(l<r)
	{
		ll m=(l+r)>>1;
		if(check(m))l=m+1;
		else r=m;
	}
	printf("%lld\n",l);return 0;
}