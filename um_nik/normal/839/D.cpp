#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

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
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

const int N = (int)1e6 + 7;
int cnt[N];
ll p2[N];
ll a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = add(p2[i - 1], p2[i - 1]);
	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 1; i < N; i++) {
		int y = 0;
		for (int j = i; j < N; j += i)
			y += cnt[j];
		if (y == 0) continue;
		a[i] = mult(y, p2[y - 1]);
	}
	ll ans = 0;
	for (int x = N - 1; x > 1; x--) {
		for (int y = 2 * x; y < N; y += x)
			a[x] = sub(a[x], a[y]);
		ans = add(ans, mult(x, a[x]));
	}
	printf("%lld\n", ans);

	return 0;
}