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

const int INF = (int)1e9;
const int N = 100100;
int a[N][2];
int n;

int solve(int t) {
	int l = -INF, r = INF;
	for (int i = 0; i < n; i++) {
		l = max(l, a[i][0] - (t - a[i][1]));
		r = min(r, a[i][0] + (t - a[i][1]));
	}
	if (l > r) return -INF;
	return r;
}
void solve() {
	scanf("%d", &n);
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i][k]);
			a[i][k] *= 2;
		}
	int l = -1, r = INF;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x) == -INF)
			l = x;
		else
			r = x;
	}
	//printf("time = %d\n", r);
	printf("%.5lf\n", (double)solve(r) / 2);
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