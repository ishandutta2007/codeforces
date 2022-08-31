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

const int IT = 70;
const int N = 100100;
int n;
int a[N];
int L;

double getLeft(double T) {
	double x = 0;
	int v = 1;
	for (int i = 0; i < n; i++) {
		double t = (a[i] - x) / v;
		if (t < T) {
			T -= t;
			x = a[i];
			v++;
		} else {
			return x + v * T;
		}
	}
	return x + v * T;
}
double getRight(double T) {
	double x = L;
	int v = 1;
	for (int i = n - 1; i >= 0; i--) {
		double t = (x - a[i]) / v;
		if (t < T) {
			T -= t;
			x = a[i];
			v++;
		} else {
			return x - v * T;
		}
	}
	return x - v * T;
}


bool solve(double T) {
//	double l = getLeft(T), r = getRight(T);
//	eprintf("%.5lf %.5lf %.5lf\n", T, l, r);
	return getLeft(T) >= getRight(T);
}

void solve() {
	scanf("%d%d", &n, &L);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	double l = 0, r = L;
	for (int it = 0; it < IT; it++) {
		double x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	printf("%.13lf\n", r);
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