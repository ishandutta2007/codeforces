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
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = (ll)1e17;
const int N = 600600;
const int LOG = 20;
int n;
int p2[N];
ll m;
ll a[N][2];
ll xs[N];
ll b[N];
ll c[N];
int k;
ll sparse[LOG][N];

ll getMax(int l, int r) {
	if (l >= r) return -INF;
	int t = p2[r - l];
	return max(sparse[t][l], sparse[t][r - (1 << t)]);
}

void solve() {
	scanf("%d%lld", &n, &m);
	k = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i][0], &a[i][1]);
		xs[k++] = a[i][0] - a[i][1];
		xs[k++] = a[i][0];
		xs[k++] = a[i][0] + a[i][1];
	}
	sort(xs, xs + k);
	k = unique(xs, xs + k) - xs;
	for (int i = 0; i <= k; i++)
		b[i] = c[i] = 0;
	for (int i = 0; i < n; i++) {
		int pos;
		pos = lower_bound(xs, xs + k, a[i][0] - a[i][1]) - xs;
		b[pos]++;
		pos = lower_bound(xs, xs + k, a[i][0]) - xs;
		b[pos] -= 2;
		pos = lower_bound(xs, xs + k, a[i][0] + a[i][1]) - xs;
		b[pos]++;
	}
	ll w = 0;
	ll d = 0;
	for (int i = 0; i < k; i++) {
		if (i > 0) w += d * (xs[i] - xs[i - 1]);
		d += b[i];
		b[i] = w;
	}
	assert(w == 0 && d == 0);
	for (int i = 0; i < n; i++)
		c[i] = 0;

	for (int i = 0; i < k; i++)
		sparse[0][i] = b[i];
	for (int t = 0; t < LOG - 1; t++)
		for (int i = 0; i + (1 << (t + 1)) <= k; i++)
			sparse[t + 1][i] = max(sparse[t][i], sparse[t][i + (1 << t)]);
	for (int i = 0; i < n; i++) {
		int p = lower_bound(xs, xs + k, a[i][0] - a[i][1]) - xs;
		int q = lower_bound(xs, xs + k, a[i][0] + a[i][1]) - xs;
		c[i] = max(c[i], getMax(0, p));
		c[i] = max(c[i], getMax(q, k));
	}

	for (int i = 0; i < k; i++)
		sparse[0][i] = b[i] - xs[i];
	for (int t = 0; t < LOG - 1; t++)
		for (int i = 0; i + (1 << (t + 1)) <= k; i++)
			sparse[t + 1][i] = max(sparse[t][i], sparse[t][i + (1 << t)]);
	for (int i = 0; i < n; i++) {
		int p = lower_bound(xs, xs + k, a[i][0] - a[i][1]) - xs;
		int q = lower_bound(xs, xs + k, a[i][0]) - xs;
		c[i] = max(c[i], getMax(p, q + 1) + (a[i][0] - a[i][1]));
	}

	for (int i = 0; i < k; i++)
		sparse[0][i] = b[i] + xs[i];
	for (int t = 0; t < LOG - 1; t++)
		for (int i = 0; i + (1 << (t + 1)) <= k; i++)
			sparse[t + 1][i] = max(sparse[t][i], sparse[t][i + (1 << t)]);
	for (int i = 0; i < n; i++) {
		int p = lower_bound(xs, xs + k, a[i][0]) - xs;
		int q = lower_bound(xs, xs + k, a[i][0] + a[i][1]) - xs;
		c[i] = max(c[i], getMax(p, q + 1) - (a[i][0] + a[i][1]));
	}

	for (int i = 0; i < n; i++) {
		if (c[i] <= m)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}