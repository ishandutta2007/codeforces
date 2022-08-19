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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int INF = (int)1e9 + 7;
const int N = 300500;
int a[N];
int A, B;
set<int> q;
int M = 0;
ll m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%d%d", &m, &A, &B);
	m++;
	q.insert(0);
	for (int i = 0; i < N; i++)
		a[i] = INF;
	while(!q.empty()) {
		int x = *q.begin();
		q.erase(q.begin());
		M = max(M, x);
		a[x] = M;
		if (x + A < N && a[x + A] == INF) q.insert(x + A);
		if (x - B >= 0 && a[x - B] == INF) q.insert(x - B);
	}

	ll ans = 0;
	for (int x = 0; x < N; x++) {
		if (a[x] < m) ans += m - a[x];
	}
	if (m > N) {
		int g = gcd(A, B);
		int l = (N - 1) / g - 1;
		int r = m / g + 2;
		while(l * g < N) l++;
		while((r - 1) * g >= m) r--;
		ans += m * (r - l);
		ans -= (ll)g * (r - l) * (l + r - 1) / 2;
	}
	printf("%lld\n", ans);

	return 0;
}