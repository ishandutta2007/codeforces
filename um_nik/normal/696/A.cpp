#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

typedef long long ll;
map<ll, ll> a;

void addQ()
{
	ll v, u, w;
	scanf("%lld%lld%lld", &v, &u, &w);
	while(v != u)
	{
		if (v < u) swap(v, u);
		a[v] += w;
		v /= 2;
	}
	return;
}

ll getQ()
{
	ll v, u;
	scanf("%lld%lld", &v, &u);
	ll res = 0;
	while(v != u)
	{
		if (v < u) swap(v, u);
		res += (a.count(v) > 0 ? a[v] : 0);
		v /= 2;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	while(q--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
			addQ();
		else
			printf("%lld\n", getQ());
	}

	return 0;
}