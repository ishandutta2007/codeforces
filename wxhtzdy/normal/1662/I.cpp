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

const int N = 200050;
int n, m;
int p[N];
int x[N];
set<int> setik;

bool badSeg(int l, int r) {
	auto it = setik.lower_bound(l);
	if (it != setik.end() && *it >= l && *it <= r)
		return true;
	return false;
}

bool check(ll r) {
	int ptr = 0;
	ll s = 0;
	vector<pii> segs;
	for (int i = 0; i < n; i++) {
		while (ptr < n && s < r) {
			s += p[ptr];
			ptr += 1;
		}
		if (s >= r)
			segs.emplace_back(i, ptr - 1);
		s -= p[i];
	}
	for (auto& seg : segs) {
		int L = seg.fi;
		int R = seg.se;
		if (badSeg(L * 100, R * 100))
			continue;
		ll toL, toR;
		if (L * 100 < x[0])
			toL = (ll)-1e17;
		else
			toL = *prev(setik.lower_bound(L * 100 + 1));
		if (R * 100 > x[m - 1])
			toR = (ll)1e17;
		else
			toR = *setik.lower_bound(R * 100);
		ll dL = L * 100 - toL;
		ll dR = toR - R * 100;
		if (dL + dR > (R - L) * 100)
			return true;
	}
	return false;
}

int main()
{
	startTime = clock();

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < m; i++)
		setik.insert(x[i]);
	sort(x, x + m);
	ll l = 0, r = 1e16;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	printf("%lld", l);

	return 0;
}