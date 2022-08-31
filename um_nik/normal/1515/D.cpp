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

const int N = 300300;
int n;
int a[N][2];

void solve() {
	int l, r;
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; i++)
		a[i][0] = a[i][1] = 0;
	int ans = abs(r - l);
	for (int i = 0; i < l; i++) {
		int x;
		scanf("%d", &x);
		x--;
		a[x][0]++;
	}
	for (int i = 0; i < r; i++) {
		int x;
		scanf("%d", &x);
		x--;
		a[x][1]++;
	}
	for (int i = 0; i < n; i++) {
		while(l < r && a[i][0] + 2 <= a[i][1]) {
			l++;
			r--;
			a[i][0]++;
			a[i][1]--;
		}
		while(r < l && a[i][1] + 2 <= a[i][0]) {
			r++;
			l--;
			a[i][1]++;
			a[i][0]--;
		}
		ans += abs(a[i][1] - a[i][0]);
	}
	printf("%d\n", ans / 2);
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