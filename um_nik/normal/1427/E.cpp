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
ll ans[N][3];
int ansSz;

void addAns(ll x, ll y, ll z) {
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ans[ansSz][2] = z;
	ansSz++;
}

bool isPow2(ll x) {
	return (x > 0 && (x & (x - 1)) == 0);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll x;
	scanf("%lld", &x);
	int k = 0;
	while((1LL << (k + 1)) <= x) k++;
	assert(k > 0);
	ll y = x;
	for (int i = 0; i < k; i++) {
		addAns(y, 1, y);
		y += y;
	}
	ll z = x + y;
	addAns(x, 1, y);
	addAns(z, 0, x);
	z ^= x;
	addAns(z, 0, y);
	z ^= y;
	assert(z != 0);

	if (!isPow2(z)) {
		ll p = z + z;
		addAns(z, 1, z);
		addAns(z, 0, p);
		z ^= p;
		int n = 0;
		while(((z >> n) & 1) == 0) n++;
		int m = n + 1;
		while(((z >> m) & 1) == 0) m++;
		assert(z == ((1LL << n) + (1LL << m)));
		assert(m + (m - n) < 61);
		y = z;
		for (int i = 0; i < m - n; i++) {
			addAns(y, 1, y);
			y += y;
		}
		p = y + z;
		addAns(y, 1, z);
		addAns(p, 0, y);
		p ^= y;
		addAns(p, 0, z);
		p ^= z;
		assert(isPow2(p));
		z = p;
	}

	while(z <= x) {
		if (x & z) {
			addAns(x, 0, z);
			x ^= z;
		}
		addAns(z, 1, z);
		z += z;
	}

	while(x > 1) {
		y = x;
		while(!isPow2(y)) {
			addAns(y, 1, y);
			y += y;
			if (y & z) {
				addAns(y, 0, z);
				y ^= z;
			}
		}
		assert(y < z);
		ll p = y;
		while(p < z) {
			addAns(p, 1, p);
			p += p;
		}
		z = y;
		while(x >= z) {
			int k = 0;
			while((1LL << (k + 1)) <= x) k++;
			addAns(x, 0, 1LL << k);
			x ^= 1LL << k;
		}
	}

	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++) {
		printf("%lld %c %lld\n", ans[i][0], (ans[i][1] == 0 ? '^' : '+'), ans[i][2]);
	}

	return 0;
}