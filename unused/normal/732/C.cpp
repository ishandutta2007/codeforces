#include "bits/stdc++.h"
using namespace std;

long long getans(long long a, long long b, long long c)
{
	if (a<0||b<0||c<0) return LLONG_MAX;
	long long mv = max({a,b,c});
	return mv-a+mv-b+mv-c;
}

int main()
{
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);

	long long ans = getans(a,b,c);
	ans = min(ans, getans(a-1,b,c));
	ans = min(ans, getans(a,b-1,c));
	ans = min(ans, getans(a,b,c-1));
	ans = min(ans, getans(a-1,b-1,c));
	ans = min(ans, getans(a-1,b,c-1));
	ans = min(ans, getans(a,b-1,c-1));
	printf("%lld", ans);
}