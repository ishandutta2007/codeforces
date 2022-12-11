#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

#include <functional>
#include <complex>
#include <valarray>
#include <cassert>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
	if (p == 0) return 1;
	if (p == 2 || (p & 1)) return mult(x, bin_pow(x, p - 1));
	return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}


const int N = (int)1e6 + 10;
int n;
int a[N];
ll f[N];
bool used[N];
int group_cnt[N];
int group_id[N];
int mask_cnt[N];
int d[N];
bool isEmpty[N];
int goTo[N];
int goFrom[N];

void precalc()
{
	for (int i = 2; i < N; i++)
		d[i] = -1;
	for (int x = 2; x < N; x++)
	{
		if (d[x] != -1) continue;
		for (int y = x; y < N; y += x)
			if (d[y] == -1)
				d[y] = x;
	}

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);

	return;
}

bool trySetTo(int x, int y)
{
	if (goTo[x] != 0 && goTo[x] != y) return false;
	goTo[x] = y;
	return true;
}
bool trySetFrom(int x, int y)
{
	if (goFrom[x] != 0 && goFrom[x] != y) return false;
	goFrom[x] = y;
	return true;
}

bool tryMatch(int x, int y)
{
	if (isEmpty[x] ^ isEmpty[y]) return false;
	if (isEmpty[x])
	{
		if (!trySetTo(x, y)) return false;
		if (!trySetFrom(y, x)) return false;
		return true;
	}
	while(x > 1 && y > 1)
	{
		int xx = d[x], yy = d[y];
		if (group_id[xx] != group_id[yy]) return false;
		if (!trySetTo(xx, yy)) return false;
		if (!trySetFrom(yy, xx)) return false;
		while (x % xx == 0) x /= xx;
		while (y % yy == 0) y /= yy;
	}
	if (x > 1 || y > 1) return false;
	return true;
}

int getMask(int x)
{
	if (isEmpty[x]) return 1;
	int mask = 1;
	while(x > 1)
	{
		int y = d[x];
		mask *= y;
		while(x % y == 0) x /= y;
	}
	return mask;
}

ll solve()
{
	for (int x = 2; x <= n / 2; x++)
	{
		if (d[x] != x) continue;
		group_id[x] = n / x;
		group_cnt[group_id[x]]++;
	}
	isEmpty[1] = 1;
	for (int x = (n / 2) + 1; x <= n; x++)
		if (d[x] == x)
		{
			isEmpty[x] = 1;
		}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0) continue;
		used[a[i]] = 1;
		int x = a[i];
		int y = i;
		if (!tryMatch(x, y)) return 0;
	}
	for (int x = 2; x <= n / 2; x++)
	{
		if (d[x] != x) continue;
		if (goTo[x] == 0) continue;
		group_cnt[group_id[x]]--;
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++)
		if (group_cnt[i] > 1)
			ans = mult(ans, f[group_cnt[i]]);
	for (int x = 1; x <= n; x++)
	{
		if (used[x]) continue;
		mask_cnt[getMask(x)]++;
	}
	for (int i = 1; i <= n; i++)
		if (mask_cnt[i] > 1)
			ans = mult(ans, f[mask_cnt[i]]);
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	precalc();

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%lld\n", solve());

	return 0;
}