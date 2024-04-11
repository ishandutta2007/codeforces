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

const int C = 200;

int XL, XR, YL, YR;

int query(vector<pii> q) {
#ifdef LOCAL
	int res = 0;
	for (pii t : q)
		res += (int)(XL <= t.first && t.first <= XR && YL <= t.second && t.second <= YR);
	return res;
#endif
	printf("? %d\n", (int)q.size());
	for (pii t : q)
		printf("%d %d ", t.first, t.second);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}


int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

#ifdef LOCAL
	scanf("%d%d%d%d", &XL, &YL, &XR, &YR);
#endif

	vector<pii> q;
	for (int x = 1; x <= C; x++)
		for (int y = 1; y <= C; y++)
			q.push_back(mp(x, y));
	int S = query(q);
	int l = 0, r = 8;
	int SL = 0;
	while(r - l > 1) {
		int z = (l + r) / 2;
		q.clear();
		for (int x = 1; x <= C; x++) {
			if (x % (1 << z) == 0) continue;
			for (int y = 1; y <= C; y++)
				q.push_back(mp(x, y));
		}
		int cur = query(q);
		if (cur < S) {
			SL = cur;
			l = z;
		} else {
			r = z;
		}
	}
	int Q = S - SL;
	assert(S % Q == 0);
	int P = S / Q;
	//eprintf("P = %d, Q = %d\n", P, Q);
	printf("! %d\n", 2 * (P + Q - 2));
	fflush(stdout);

	return 0;
}