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

struct Frac {
	ll p, q;

	Frac() : p(0), q(1) {}
	Frac(ll _p ,ll _q) {
		p = _p;
		q = _q;
		if (q < 0) {
			p *= -1;
			q *= -1;
		}
	}

	bool operator < (const Frac &F) const {
		return p * F.q < F.p * q;
	}
	bool operator == (const Frac &F) const {
		return p * F.q == F.p * q;
	}
};

const int N = 2020;
const int M = N * N / 2;
double ANS = 1e30;
int n;

struct Segm {
	ll x1, x2, y;

	Segm() : x1(), x2(), y() {}

	void scan() {
		scanf("%lld%lld%lld", &x1, &x2, &y);
	}

	bool operator < (const Segm &S) const {
		return y < S.y;
	}
};

Segm a[N];
pair<Frac, Frac> b[M];
pair<Frac, int> c[N], d[N];
int cSz, dSz;
int m;

Frac getInter(ll x1, ll y1, ll x2, ll y2) {
	return Frac(x2 - x1, y1 - y2);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i].scan();
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (a[i].y == a[j].y) continue;
			Frac L = getInter(a[i].x1, a[i].y, a[j].x2, a[j].y);
			Frac R = getInter(a[i].x2, a[i].y, a[j].x1, a[j].y);
			if (R < L) swap(L, R);
			b[m++] = mp(L, R);
		}
	sort(b, b + m);

	if (m == 0) {
		ll minX = (ll)1e18, maxX = (ll)-1e18;
		for (int i = 0; i < n; i++) {
			minX = min(minX, a[i].x1);
			maxX = max(maxX, a[i].x2);
		}
		printf("%lld\n", maxX - minX);
		return 0;
	}

	int mm = 1;
	for (int i = 1; i < m; i++) {
		if (b[i].first < b[mm - 1].second) {
			b[mm - 1].second = max(b[mm - 1].second, b[i].second);
		} else {
			b[mm++] = b[i];
		}
	}
	m = mm;

	for (int i = n - 1; i >= 0; i--) {
		while(cSz > 0) {
			int id = c[cSz - 1].second;
			Frac P = c[cSz - 1].first;
			if (a[id].x1 * P.q + a[id].y * P.p > a[i].x1 * P.q + a[i].y * P.p) {
				cSz--;
				continue;
			}
			if (a[id].y == a[i].y) break;
			c[cSz++] = mp(getInter(a[i].x1, a[i].y, a[id].x1, a[id].y), i);
			break;
		}
		if (cSz == 0) c[cSz++] = mp(b[0].first, i);
	}
	for (int i = 0; i < n; i++) {
		while(dSz > 0) {
			int id = d[dSz - 1].second;
			Frac P = d[dSz - 1].first;
			if (a[id].x2 * P.q + a[id].y * P.p < a[i].x2 * P.q + a[i].y * P.p) {
				dSz--;
				continue;
			}
			if (a[id].y == a[i].y) break;
			d[dSz++] = mp(getInter(a[i].x2, a[i].y, a[id].x2, a[id].y), i);
			break;
		}
		if (dSz == 0) d[dSz++] = mp(b[0].first, i);
	}

	int cP = 0, dP = 0;
	for (int i = 0; i < m; i++) {
		Frac P;
		double w;
		int id1, id2;

		P = b[i].first;
		w = (double)P.p / P.q;
		while(cP + 1 < cSz && c[cP + 1].first < P) cP++;
		while(dP + 1 < dSz && d[dP + 1].first < P) dP++;
		id1 = c[cP].second; id2 = d[dP].second;
		ANS = min(ANS, a[id2].x2 + a[id2].y * w - a[id1].x1 - a[id1].y * w);

		P = b[i].second;
		w = (double)P.p / P.q;
		while(cP + 1 < cSz && c[cP + 1].first < P) cP++;
		while(dP + 1 < dSz && d[dP + 1].first < P) dP++;
		id1 = c[cP].second; id2 = d[dP].second;
		ANS = min(ANS, a[id2].x2 + a[id2].y * w - a[id1].x1 - a[id1].y * w);
	}

	printf("%.15lf\n", ANS);

	return 0;
}