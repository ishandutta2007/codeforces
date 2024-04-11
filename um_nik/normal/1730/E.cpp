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

const int N = 500500;
const int M = (int)1e6 + 3;
vector<int> d[M];
int n;
int a[N];
int b[N][2];
int c[N][2];
vector<int> pos[M];
int pp[M];
int st[M];
int sz;

void solve() {
	for (int x = 0; x < M; x++) {
		if (!pos[x].empty()) pos[x].clear();
		pp[x] = 0;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	sz = -1;
	st[++sz] = -1;
	for (int i = 0; i < n; i++) {
		while(sz > 0 && a[i] > a[st[sz]]) sz--;
		b[i][0] = st[sz];
		st[++sz] = i;
	}
	sz = -1;
	st[++sz] = n;
	for (int i = n - 1; i >= 0; i--) {
		while(sz > 0 && a[i] >= a[st[sz]]) sz--;
		b[i][1] = st[sz];
		st[++sz] = i;
	}
	sz = -1;
	st[++sz] = -1;
	for (int i = 0; i < n; i++) {
		while(sz > 0 && a[i] <= a[st[sz]]) sz--;
		c[i][0] = st[sz];
		st[++sz] = i;
	}
	sz = -1;
	st[++sz] = n;
	for (int i = n - 1; i >= 0; i--) {
		while(sz > 0 && a[i] <= a[st[sz]]) sz--;
		c[i][1] = st[sz];
		st[++sz] = i;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int y : d[x]) {
			if (pos[y].empty()) continue;
			int q1 = -1, q2 = -1;
			if (pp[y] < (int)pos[y].size()) {
				q2 = pos[y][pp[y]];
				if (c[q2][0] >= i || b[i][1] <= q2) q2 = -1;
			}
			if (pp[y] > 0) {
				q1 = pos[y][pp[y] - 1];
				if (c[q1][1] <= i || b[i][0] >= q1) q1 = -1;
			}
			if (q1 != -1 && q2 != -1) {
				assert(c[q1][0] == c[q2][0]);
				assert(c[q1][1] == c[q2][1]);
				ans += (ll)(i - max(c[q1][0], b[i][0])) * (min(c[q1][1], b[i][1]) - i);
				ans -= (ll)(i - max(q1, b[i][0])) * (min(q2, b[i][1]) - i);
			} else if (q1 != -1) {
				ans += (ll)(q1 - max(c[q1][0], b[i][0])) * (min(c[q1][1], b[i][1]) - i);
			} else if (q2 != -1) {
				ans += (ll)(i - max(c[q2][0], b[i][0])) * (min(c[q2][1], b[i][1]) - q2);
			}
		}
		pp[x]++;
	}
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < M; i++)
		for (int j = i; j < M; j += i)
			d[j].push_back(i);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}