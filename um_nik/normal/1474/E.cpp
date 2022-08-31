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
int n, m;
int p[N];
int ans[N][2];

ll sqr(ll x) {
	return x * x;
}

void solve() {
	scanf("%d", &n);
	m = 0;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	ll w = 0;
	int l = 1;
	int r = n - 1;
	int t = 0;
	while(m < n - 1) {
		if (t == 0) {
			w += sqr(n - l);
			ans[m][0] = l;
			ans[m][1] = n;
			m++;
			swap(p[l], p[n]);
			l++;
		} else {
			w += sqr(r - 1);
			ans[m][0] = r;
			ans[m][1] = 1;
			m++;
			swap(p[r], p[1]);
			r--;
		}
		t ^= 1;
	}
	printf("%lld\n", w);
	for (int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	printf("\n");
	printf("%d\n", m);
	for (int i = m - 1; i >= 0; i--)
		printf("%d %d\n", ans[i][0], ans[i][1]);
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