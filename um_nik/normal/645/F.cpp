#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if(x < 0) x += MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
	if (p == 0) return 1;
	if (p == 2) return mult(x, x);
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}

const int C = (int)1e6 + 3;
vector<int> d[C];
ll mu[C];
ll f[C], rf[C];
int n, q, k;
ll ans;
int a[C];
ll r[C];

ll getC(int n, int k)
{
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

void precalc()
{
	f[0] = 1;
	for (int i = 1; i < C; i++)
		f[i] = mult(f[i - 1], i);
	rf[C - 1] = rev(f[C - 1]);
	for (int i = C - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	mu[1] = 1;
	for (int x = 1; x < C; x++)
		for (int y = 2 * x; y < C; y += x)
			mu[y] -= mu[x];
	

	for (int x = 1; x < C; x++)
		for (int y = x; y < C; y += x)
			d[y].push_back(x);

	for (int x = 1; x < C; x++)
	{
		for (int y : d[x])
			r[x] = add(r[x], mult(y, mu[x / y] + MOD));
	}

	return;
}


void add(int x)
{
	ans = sub(ans, mult(r[x], getC(a[x], k)));
	a[x]++;
	ans = add(ans, mult(r[x], getC(a[x], k)));
	return;
}

void query()
{
	int x;
	scanf("%d", &x);
	for (int y : d[x])
		add(y);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();
	scanf("%d%d%d", &n, &k, &q);
	while(n--)
		query();
	while(q--)
	{
		query();
		printf("%lld\n", ans);
	}

	return 0;
}