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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

const int N = 200200;
ll ANS;
int n;
pll a[N];
ll M;

bool cmp(const pll &_v, const pll &_u) {
	pll v = _v, u = _u;
	if (v.first < 0) {
		v.first *= -1;
		v.second *= -1;
	}
	if (u.first < 0) {
		u.first *= -1;
		u.second *= -1;
	}
	ll x = v.first * u.second - v.second * u.first;
	if (x != 0) return x < 0;
	if (_v.first * _u.first > 0)
		return _v.first < _u.first;
	else
		return _v.first > 0;
}

int fenv[N];
void addFenv(int r) {
	for(; r < N; r |= r + 1)
		fenv[r]++;
}
int getFenv(int r) {
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}

void solve() {
	for (int i = 0; i < N; i++)
		fenv[i] = 0;
	sort(a, a + n, cmp);
//	for (int i = 0; i < n; i++)
//		printf("%lld %lld\n", a[i].first, a[i].second);
	for (int i = 0; i < n; i++) {
		ll x = a[i].first + N / 2;
		ll old = ANS;
		if (a[i].first > 0) {
			ANS += getFenv(x - 1);
			ANS -= getFenv(N / 2);
		} else {
			ANS += getFenv(x - 1);
			ANS += getFenv(N - 1);
			ANS -= getFenv(N / 2);
		}
		//printf("%lld\n", ANS - old);
		addFenv(x);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &M);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i].first, &a[i].second);
	}

	ANS = -((ll)n * (n - 1) / 2);
	sort(a, a + n);
	int len = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].first != a[i - 1].first) len = 0;
		len++;
		ANS += len - 1;
	}

	for (int i = 0; i < n; i++) {
		a[i].second += M;
	}
	solve();
//	printf("%lld\n", ANS);
	for (int i = 0; i < n; i++)
		a[i].second -= M;
	for (int i = 0; i < n; i++) {
		a[i].first *= -1;
		a[i].second *= -1;
	}
	for (int i = 0; i < n; i++)
		a[i].second += M;
	solve();

	printf("%lld\n", ANS);

	return 0;
}