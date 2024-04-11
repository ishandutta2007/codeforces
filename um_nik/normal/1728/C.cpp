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

int getLog(int x) {
	int ans = 0;
	while(x > 0) {
		ans++;
		x /= 10;
	}
	return ans;
}

void solve() {
	multiset<int> a, b;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.insert(-x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		b.insert(-x);
	}
	int ans = 0;
	while(!a.empty()) {
		assert(!b.empty());
		int x = -(*a.begin());
		int y = -(*b.begin());
		if (x == y) {
			a.erase(a.begin());
			b.erase(b.begin());
			continue;
		}
		if (x > y) {
			a.erase(a.begin());
			a.insert(-getLog(x));
			ans++;
		} else {
			b.erase(b.begin());
			b.insert(-getLog(y));
			ans++;
		}
	}
	printf("%d\n", ans);
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