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

const int N = 10100;
int n;
ll a[N];
int l[N], r[N];
pll b[N], c[N];
int m, k;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++) {
		l[i] = i - 1;
		r[i] = i + 1;
		while(l[i] > -1 && a[i] < a[l[i]]) l[i]--;
		while(r[i] < n && a[i] <= a[r[i]]) r[i]++;
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ll A = 0, B = 0;
		for (int j = 0; j < i; j++)
			A = max(A, a[j] * (min(i, r[j]) - l[j] - 1));
		for (int j = i; j < n; j++)
			B = max(B, a[j] * (r[j] - max(i - 1, l[j]) - 1));
		ans = max(ans, A + B);
	}
	//eprintf("ans = %lld\n", ans);
	for (int i = 0; i < n; i++) {
		int L = l[i], R = r[i];
		ll X = a[i];
		ll cur = 0;
		int len = 0;
		while(L > -1 && R < n) {
			len++;
			if (a[L] > a[R]) {
				X = min(X, a[L]);
				L--;
			} else {
				X = min(X, a[R]);
				R++;
			}
			cur = max(cur, X * len);
		}
		while(L > -1) {
			len++;
			X = min(X, a[L]);
			L--;
			cur = max(cur, X * len);
		}
		while(R < n) {
			len++;
			X = min(X, a[R]);
			R++;
			cur = max(cur, X * len);
		}
		//eprintf("%d %d %d %lld\n", i, l[i], r[i], cur);
		ans = max(ans, cur + (r[i] - l[i] - 1) * a[i]);
	}
	//eprintf("ans = %lld\n", ans);
	for (int i = 0; i < n; i++) {
		m = k = 0;
		ll X = a[i];
		for (int j = l[i]; j >= 0; j--) {
			X = min(X, a[j]);
			b[m++] = mp(X, r[i] - j);
		}
		X = a[i];
		for (int j = r[i]; j < n; j++) {
			X = min(X, a[j]);
			c[k++] = mp(X, j - l[i]);
		}
		int pos = k - 1;
		ll bst = 0;
		for (int j = 0; j < m; j++) {
			while(pos >= 0 && c[pos].first + b[j].first <= a[i]) {
				bst = max(bst, c[pos].first * c[pos].second);
				pos--;
			}
			ans = max(ans, bst + b[j].first * b[j].second);
		}
		pos = k - 1;
		for (int j = 0; j < m; j++) {
			while(pos >= 0 && c[pos].first + b[j].first <= a[i]) pos--;
			if (pos >= 0)
				ans = max(ans, (a[i] - b[j].first) * c[pos].second + b[j].first * b[j].second);
		}
		pos = m - 1;
		for (int j = 0; j < k; j++) {
			while(pos >= 0 && b[pos].first + c[j].first <= a[i]) pos--;
			if (pos >= 0)
				ans = max(ans, (a[i] - c[j].first) * b[pos].second + c[j].first * c[j].second);
		}
	}
	printf("%lld\n", ans);

	return 0;
}