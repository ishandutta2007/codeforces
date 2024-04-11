#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

	long long ans = 0;
	long long aa = min({ a, c, d });
	ans += aa * 256;
	a -= aa; c -= aa; d -= aa;

	long long bb = min({ a, b });
	ans += bb * 32;

	printf("%lld", ans);
}