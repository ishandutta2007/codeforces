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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100;
const ll INF = (ll)3e16;
ll a[N][2];
int n;

void read() {
	scanf("%lld%lld", &a[0][0], &a[0][1]);
	ll ax, ay, bx, by;
	scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
	n = 0;
	while(a[n][0] < INF && a[n][1] < INF) {
		n++;
		a[n][0] = ax * a[n - 1][0] + bx;
		a[n][1] = ay * a[n - 1][1] + by;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	ll x, y, t;
	scanf("%lld%lld%lld", &x, &y, &t);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (abs(x - a[i][0]) + abs(y - a[i][1]) + abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]) <= t)
				ans = max(ans, abs(i - j) + 1);
		}
	printf("%d\n", ans);

	return 0;
}