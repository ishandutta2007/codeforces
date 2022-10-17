#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> o;
int n;
ll r, h, s;
int main()
{
	scanf("%d", &n);
	o[0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &r, &h);
		h *= r * r;
		auto l = --o.lower_bound(h);
		for (s = l++->second + h; l != o.end() && l->second < s; o.erase(l++))
			;
		o[h] = s;
	}
	printf("%.9f\n", o.rbegin()->second * acos(-1));
	return 0;
}