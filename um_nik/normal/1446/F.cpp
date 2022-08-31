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

const double PI = 4 * atan(1.);

const int IT = 80;
const double INF = 2e4;
const int N = 200100;
int n;
double a[N][2];
int b[N][2];
pair<double, int> ord[N];
int m;


struct Fenwick {
	vector<int> fenv;

	Fenwick() : fenv() {}
	Fenwick(int n) : fenv(vector<int>(n, 0)) {}

	void add(int p, int x) {
		for(; p < (int)fenv.size(); p |= p + 1)
			fenv[p] += x;
	}
	int get(int r) {
		int res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += fenv[r];
		return res;
	}
	int getSum(int l, int r) {
		if (l >= r) return 0;
		return get(r - 1) - get(l - 1);
	}
} fenv;

double normAng(double ang) {
	while(ang >= 2 * PI) ang -= 2 * PI;
	while(ang < 0) ang += 2 * PI;
	return ang;
}

ll solve(double R) {
//	printf("solve %.5lf\n", R);
	m = 0;
	for (int i = 0; i < n; i++) {
		double L = sqrt(a[i][0] * a[i][0] + a[i][1] * a[i][1]);
		if (L <= R) continue;
		m++;
		double ang = atan2(a[i][1], a[i][0]);
		double phi = acos(R / L);
//		printf("%.5lf %.5lf\n", ang, phi);
		ord[2 * m - 2] = mp(normAng(ang - phi), -m);
		ord[2 * m - 1] = mp(normAng(ang + phi), m);
	}
	sort(ord, ord + 2 * m);
	for (int i = 0; i < 2 * m; i++) {
		int v = ord[i].second;
		if (v < 0) {
			b[-v][0] = i;
		} else {
			b[v][1] = i;
		}
	}
	fenv = Fenwick(2 * m);
	for (int i = 1; i <= m; i++) {
//		printf("%d %d\n", b[i][0], b[i][1]);
		if (b[i][0] > b[i][1])
			fenv.add(b[i][0], 1);
	}
	ll ans = 0;
	for (int i = 0; i < 2 * m; i++) {
		int v = ord[i].second;
		if (v < 0) {
			v *= -1;
			
			fenv.add(i, 1);
		} else {

			fenv.add(b[v][0], -1);
			if (b[v][0] < b[v][1]) {
				ans += fenv.getSum(b[v][0], b[v][1]);
			} else {
				ans += fenv.getSum(b[v][0], 2 * m) + fenv.getSum(0, b[v][1]);
			}
		}
	}
//	printf("ans = %lld\n", ans);
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll k;
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			scanf("%lf", &a[i][j]);
	double l = 0, r = INF;
//	solve(0.5);
	for (int it = 0; it < IT; it++) {
		double x = (l + r) / 2;
		ll z = solve(x);
		if (k + z > (ll)n * (n - 1) / 2)
			l = x;
		else
			r = x;
	}
	printf("%.15lf\n", l);

	return 0;
}