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

const ll INF = (ll)1e18;
const int N = (int)1e6 + 100;
bool p[N];
ll X, Y;
ll sum[2 * N];
ll sumVal[2 * N];
ll ans = INF;

void read() {
	int n;
	scanf("%d%lld%lld", &n, &X, &Y);
	while(n--) {
		int z;
		scanf("%d", &z);
		sum[z]++;
		sumVal[z] += z;
	}
	for (int i = 1; i < 2 * N; i++)
		sum[i] += sum[i - 1];
	for (int i = 1; i < 2 * N; i++)
		sumVal[i] += sumVal[i - 1];
}

ll solve(ll k) {
	ll d = X / Y;
	d = min(d, k - 1);
	ll res = 0;
	for (ll x = k; x < 2 * N; x += k) {
		res += X * (sum[x - d - 1] - sum[x - k]);
		ll cnt = sum[x] - sum[x - d - 1];
		ll val = cnt * x - (sumVal[x] - sumVal[x - d - 1]);
		res += val * Y;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int i = 2; i < N; i++)
		p[i] = 1;
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		ans = min(ans, solve(i));
		for (int j = 2 * i; j < N; j += i)
			p[j] = 0;
	}
	printf("%lld\n", ans);

	return 0;
}