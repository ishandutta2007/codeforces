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
const int N = 3030;
ll ans = 0;
int n;
ll a[N];
ll L, R;
map<ll, int> m;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	n -= n & 1;
	L = R = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			R += a[i];
		} else {
			ll X = R - a[i];
			ans += R - max(X, L);
			for (auto t : m) {
				if (X <= t.first && t.first < R) {
					ans += t.second;
				}
			}
			R = X;
			if (L > X) {
				L = X;
				m.clear();
			} else {
				while(!m.empty() && m.rbegin()->first > X)
					m.erase(m.rbegin()->first);
				m[X]++;
			}
		}
	}
	printf("%lld\n", ans);

	return 0;
}