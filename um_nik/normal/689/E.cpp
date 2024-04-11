#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
typedef long long ll;

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
	if (p == 0) return 1;
	if (p % 2 == 1 || p == 2) return mult(x, bin_pow(x, p - 1));
	return bin_pow(bin_pow(x, 2), p / 2);
}
ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}

const int N = (int)5e5 + 10;
int n;
int k;
ll f[N], rf[N];

ll getC(int n, int k)
{
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

pii a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		r++;
		a[2 * i] = mp(l, 1);
		a[2 * i + 1] = mp(r, -1);
	}
	sort(a, a + 2 * n);
	ll ans = 0;
	int bal = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (bal >= k)
		{
			int len = a[i].first - a[i - 1].first;
			ans = add(ans, mult(len % MOD, getC(bal, k)));
		}
		bal += a[i].second;
	}
	printf("%lld\n", ans);

	return 0;
}