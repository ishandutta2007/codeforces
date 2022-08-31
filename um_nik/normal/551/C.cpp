#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int N = 100100;
int n;
ll m;
ll a[N];
ll b[N];
ll ans;

bool check(ll v)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	int k = n;
	for (int i = 0; i < m; i++)
	{
		ll mv = v - k;
		while(k > 0 && b[k - 1] <= mv)
		{
			k--;
			mv -= b[k];
		}
		if (k > 0)
			b[k - 1] -= mv;

		while(k > 0 && b[k - 1] == 0) k--;
	}
	return k == 0;
}

int main()
{
	scanf("%d%I64d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	while(a[n - 1] == 0) n--;
	ll L = n;
	ll R = (ll)1e15;
	while(R - L > 1)
	{
		ll v = (L + R) / 2;
		if (check(v))
			R = v;
		else
			L = v;
	}
	cout << R << endl;

	
	return 0;
}