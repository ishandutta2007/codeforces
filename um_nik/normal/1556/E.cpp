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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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

const int N = 100100;
const int LOG = 17;
pll sparse[LOG][N];
int p2[N];
ll a[N];
int n, q;

pll merge(pll v, pll u) {
	return mp(min(v.first, u.first), min(v.second, u.second));
}

pll getSparse(int l, int r) {
	int k = p2[r - l];
	return merge(sparse[k][l], sparse[k][r - (1 << k)]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i + 1]);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		a[i + 1] = a[i] + x - a[i + 1];
	}

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;
	n++;
	for (int i = 0; i < n; i++)
		sparse[0][i] = mp(a[i], -a[i]);
	for (int k = 0; k < LOG - 1; k++) {
		for (int i = 0; i + (1 << (k + 1)) <= n; i++)
			sparse[k + 1][i] = merge(sparse[k][i], sparse[k][i + (1 << k)]);
	}
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		pll t = getSparse(l, r);
		ll x = a[l];
		if (t.first != x || a[r] != x) {
			printf("-1\n");
		} else {
			printf("%lld\n", -t.second - x);
		}
	}

	return 0;
}