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

const int N = (1 << 18) + 7;
ll a[N];
int n;

struct Item {
	int len;
	ll sum;
	vector<ll> pref, suf, mx;

	Item() : len(), sum(), pref(), suf(), mx() {}
	Item(int _len) {
		len = _len;
		sum = 0;
		pref = vector<ll>(len, 0);
		suf = vector<ll>(len, 0);
		mx = vector<ll>(len, 0);
	}
};

Item solve(int l, int r) {
	int len = r - l;
	Item I = Item(len);
	if (len == 1) {
		I.sum = a[l];
		I.pref[0] = I.suf[0] = I.mx[0] = max(0LL, a[l]);
		return I;
	}
	Item L = solve(l, l + len / 2), R = solve(l + len / 2, r);
	I.sum = L.sum + R.sum;
	for (int i = 0; i < len / 2; i++) {
		I.pref[i] = max(L.pref[i], L.sum + R.pref[i]);
		I.suf[i] = max(R.suf[i], R.sum + L.suf[i]);
		I.mx[i] = max(max(L.mx[i], R.mx[i]), L.suf[i] + R.pref[i]);
		I.pref[i + len / 2] = max(R.pref[i], R.sum + L.pref[i]);
		I.suf[i + len / 2] = max(L.suf[i], L.sum + R.suf[i]);
		I.mx[i + len / 2] = max(max(L.mx[i], R.mx[i]), R.suf[i] + L.pref[i]);
	}
	return I;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	n = 1 << n;
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	Item I = solve(0, n);
	int q;
	int x = 0;
	scanf("%d", &q);
	while(q--) {
		int k;
		scanf("%d", &k);
		x ^= 1 << k;
		printf("%lld\n", I.mx[x]);
	}

	return 0;
}