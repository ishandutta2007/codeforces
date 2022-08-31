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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 500500;
map<pii, int> toId;
vector<double> a[N];
double s[N];
double pref[N], suf[N];
int n, m, k;
double ans = 0;

int getId(pii t) {
	if (toId.count(t) == 0) toId[t] = m++;
	return toId[t];
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int g = gcd(abs(x), abs(y));
		if (g == 0) continue;
		int id = getId(mp(x / g, y / g));
		a[id].push_back(sqrt((ll)x * x + (ll)y * y));
	}
	for (int i = 0; i < m; i++)
		sort(all(a[i]));

	for (int i = 0; i < m; i++) {
		int sz = (int)a[i].size();
		if (sz >= k) continue;
		s[i] = 0;
		double lst = 0;
		for (int j = 0; j < sz; j++) {
			double len = a[i][j] - lst;
			lst = a[i][j];
			s[i] += len * (sz - j) * (k - (sz - j));
		}
	}
	for (int i = 0; i < m; i++)
		pref[i + 1] = pref[i] + s[i];
	for (int i = m; i > 0; i--)
		suf[i - 1] = suf[i] + s[i - 1];
	/*
	for (int i = 0; i < m; i++)
		eprintf("%.5lf ", s[i]);
	eprintf("\n");
	*/
	for (int i = 0; i < m; i++) {
		int sz = (int)a[i].size();
		if (n - sz > k) continue;
		//eprintf("solving %d\n", i);
		double cur = pref[i] + suf[i + 1];
		double sumL = 0, sumR = 0;
		int w = n - sz;
		for (int j = 0; j < k - w; j++) {
			double len = (j == 0 ? a[i][0] : a[i][j] - a[i][j - 1]);
			sumL += len * (w + j) * (k - (w + j));
		}
		ans = min(ans, cur + sumL + sumR);
		for (int j = k - w - 1; j >= 0; j--) {
			double len = (j == 0 ? a[i][0] : a[i][j] - a[i][j - 1]);
			sumL -= len * (w + j) * (k - (w + j));
			len = a[i][sz - (k - w) + j];
			if (j > 0) len -= a[i][j - 1];
			ans = max(ans, cur + sumL + sumR + len * (k - w - j) * (w + j));
			//eprintf("%.5lf\n", cur + sumL + sumR + len * (k - w - j) * (w + j));
			len = a[i][sz - (k - w) + j] - a[i][sz - (k - w) + j - 1];
			sumR += len * (k - w - j) * (w + j);
		}
	}

	int p = 0;
	for (int i = 0; i < m; i++) {
		int sz = (int)a[i].size();
		for (int j = 0; j < sz; j++) {
			if (j + k < sz) continue;
			s[p++] = (k - 1 - 2 * (sz - j - 1)) * a[i][j];
		}
	}
	sort(s, s + p);
	double cur = 0;
	for (int i = 0; i < k; i++)
		cur += s[p - 1 - i];
	ans = max(ans, cur);

	printf("%.15lf\n", ans);

	return 0;
}