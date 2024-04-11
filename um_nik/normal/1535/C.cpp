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
char s[N];
int n;
int a[2][2];

void add(int pos, char c, int d) {
	if (c == '?') return;
	a[pos & 1][c - '0'] += d;
}
bool isGood() {
	for (int x = 0; x < 2; x++) {
		if (a[x][0] > 0 && a[x][1] > 0) return false;
		if (a[0][x] > 0 && a[1][x] > 0) return false;
	}
	return true;
}

void solve() {
	ll ans = 0;
	scanf("%s", s);
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++)
			a[x][y] = 0;
	n = strlen(s);
	int r = 0;
	for (int l = 0; l < n; l++) {
		while(r < n && isGood()) {
			add(r, s[r], 1);
			r++;
		}
		ans += r - l - 1;
		ans += (int)isGood();
		add(l, s[l], -1);
	}
	printf("%lld\n", ans);
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