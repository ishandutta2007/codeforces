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

vector<int> a[2];

void solve() {
	a[0].clear();
	a[1].clear();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) {
		int x;
		scanf("%d", &x);
		a[x & 1].push_back(i);
	}
	if ((int)a[0].size() & 1) {
		a[0].pop_back();
		a[1].pop_back();
	} else if (!a[0].empty()) {
		a[0].pop_back();
		a[0].pop_back();
	} else {
		a[1].pop_back();
		a[1].pop_back();
	}
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < (int)a[k].size(); i += 2)
			printf("%d %d\n", a[k][i], a[k][i + 1]);
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