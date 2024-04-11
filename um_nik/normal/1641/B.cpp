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

const int N = 505;
const int M = 2 * N * N;
int n, m, k;
int s[N];
int p[N];
pii ans1[M];
int ans2[M];
int sz1, sz2;
map<int, int> mapchik;

void myReverse(int q) {
	if (q == n - 1) return;
	for (int i = 0; i < n - q; i++) {
		ans1[sz1++] = mp(s[n - 1 - i], q + i);
	}
	ans2[sz2++] = 2 * (n - q);
	reverse(p + q, p + n);
	reverse(s + q, s + n);
}

void solve() {
	sz1 = sz2 = 0;
	mapchik.clear();
	scanf("%d", &n);
	int id = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		s[i] = x;
		if (mapchik.count(x)) {
			p[i] = mapchik[x] + n / 2;
			mapchik.erase(x);
		} else {
			p[i] = id;
			mapchik[x] = id++;
		}
	}
	if (!mapchik.empty()) {
		printf("-1\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		int q = 0;
		while(p[q] != i) q++;
		myReverse(q);
		myReverse(i);
	}
	ans2[sz2++] = n;
	eprintf("p: ");
	for (int i = 0; i < n; i++)
		eprintf("%d ", p[i]);
	eprintf("\n");
	eprintf("s: ");
	for (int i = 0; i < n; i++)
		eprintf("%d ", s[i]);
	eprintf("\n");
	
	printf("%d\n", sz1);
	for (int i = 0; i < sz1; i++)
		printf("%d %d\n", ans1[i].second, ans1[i].first);
	printf("%d\n", sz2);
	for (int i = sz2 - 1; i >= 0; i--)
		printf("%d ", ans2[i]);
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}