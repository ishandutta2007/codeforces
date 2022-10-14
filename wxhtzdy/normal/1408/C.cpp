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

const int N = 100050;
int n, l;
int x[N];

bool check(double X) {
	double L = 0, T = 0, V = 0;
	for (int i = 0; i < n; i++) {	
		double d = x[i] - L;
		if (T + (V == 0 ? 0.0 : d / V) <= X) {
			L = x[i];
			if (V != 0)
				T += d / V;
			V += 1;
		} else {
			L += V * (X - T);
			break;
		}
	}
	T = 0, V = 0;
	double R = l;
	for (int i = n - 1; i >= 0; i--) {
		double d = R - x[i];
		if (T + (V == 0 ? 0.0 : d / V) <= X) {
			R = x[i];
			if (V != 0) 
				T += d / V;
			V += 1;
		} else {
			R -= V * (X - T);
			break;
		}
	}
	return L >= R;
}

void solve() {
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	x[n++] = 0;
	x[n++] = l;
	sort(x, x + n);
	double low = 0, high = 1e9;
	for (int iter = 0; iter < 200; iter++) {
		double mid = (low + high) / 2;
		if (check(mid))
			high = mid;
		else
			low = mid;
	}
	printf("%.6lf\n", high);
}

int main()
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while(t--) solve();	

	return 0;
}