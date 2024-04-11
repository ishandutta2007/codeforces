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

const int N = 1010;
const int M = (int)1e6 + 7;
int n, m;
int a[N];
pii b[M];
int seg[M][2];
int mt[N];
int used[M];
int T;

bool dfs(int v) {
	if (used[v] == T) return false;
	used[v] = T;
	for (int i = seg[v][0]; i < seg[v][1]; i++) {
		int u = b[i].second;
		if (mt[u] == -1) {
			mt[u] = v;
			return true;
		}
	}
	shuffle(b + seg[v][0], b + seg[v][1], rng);
	for (int i = seg[v][0]; i < seg[v][1]; i++) {
		int u = b[i].second;
		if (dfs(mt[u])) {
			mt[u] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int x = 1; x <= n; x++)
			b[m++] = mp(a[i] * x, i);
	}
	sort(b, b + m);
	m = 0;
	int l = 0;
	while(l < n * n) {
		int r = l;
		while(r < n * n && b[l].first == b[r].first) r++;
		seg[m][0] = l;
		seg[m][1] = r;
		m++;
		l = r;
	}
	for (int i = 0; i < n; i++)
		mt[i] = -1;
	int sz = 0;
	ll ans = 0;
	T++;
	for (int i = 0; sz < n && i < m; i++) {
		if (dfs(i)) {
			T++;
			sz++;
			ans += b[seg[i][0]].first;
		}
	}
	assert(sz == n);
	printf("%lld\n", ans);

	return 0;
}