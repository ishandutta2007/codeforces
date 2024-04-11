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

const int N = 200200;
vector<ll> a[N];
pii ord[N];
int n;
int b[N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i] = {(ll)1e18};
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		b[i]--;
	}
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		a[b[i]].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		sort(all(a[i]));
		reverse(all(a[i]));
		a[i][0] = 0;
		for (int j = 1; j < (int)a[i].size(); j++)
			a[i][j] += a[i][j - 1];
		ord[i] = mp((int)a[i].size() - 1, i);
	}
	sort(ord, ord + n);
	reverse(ord, ord + n);
	for (int k = 1; k <= n; k++) {
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (ord[i].first < k) break;
			int v = ord[i].second;
			int sz = ord[i].first;
			sz -= sz % k;
			ans += a[v][sz];
		}
		printf("%lld ", ans);
	}
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