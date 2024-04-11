/***
5 0
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct DSU
{
	int *pa;
	int *sz;
	DSU(int n)
	{
		pa = new int[n + 1];
		sz = new int[n + 1];
		for (int i = 0; i <= n; i++)
		{
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int root(int i)
	{
		if (i == pa[i])
			return i;
		return pa[i] = root(pa[i]);
	}
	void merge(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a == b)
			return;
		if (sz[a] < sz[b])
			swap(a, b);
		sz[a] += sz[b];
		pa[b] = a;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll p, k;
	cin >> p >> k;
	if (k == 0)
	{
		ll ans = 1;
		for (int x = 1; x < p; x++)
			ans = (ans * p) % 1000000007ll;
		cout << ans << "\n";
		return 0;
	}
	DSU X(1000000);
	for (int x = 0; x < p; x++)
	{
		X.merge(x, (k * x) % p);
	}
	ll ans = 0;
	for (int x = 0; x < p; x++)
		if (x == (x * k) % p)
			ans++;
	for (int x = 1; x < p; x++)
		if (X.root(x) == x)
			ans = (ans * p) % 1000000007ll;
	cout << ans << "\n";
}