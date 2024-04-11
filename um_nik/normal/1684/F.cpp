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

const int N = 300300;
int n, m;
int a[N];
int xs[N];
int sz;
vector<int> pos[N];
bool isRight[N];
int b[N];
int c[N];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		xs[i] = a[i];
	}
	sort(xs, xs + n);
	sz = unique(xs, xs + n) - xs;
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(xs, xs + sz, a[i]) - xs;
	for (int i = 0; i < n; i++) {
		pos[i].clear();
		isRight[i] = false;
		c[i] = -1;
		b[i] = -1;
	}
	for (int i = 0; i < n; i++)
		pos[a[i]].push_back(i);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		c[l] = max(c[l], r);
	}
	for (int i = 1; i < n; i++)
		c[i] = max(c[i], c[i - 1]);
	int cur = -1;
	for (int i = n - 1; i >= 0; i--) {
		int p = lower_bound(all(pos[a[i]]), i) - pos[a[i]].begin();
		int q = lower_bound(all(pos[a[i]]), c[i]) - pos[a[i]].begin();
		if (q <= p + 1) continue;
		isRight[pos[a[i]][p + 1]] = 1;
		q--;
		cur = max(cur, pos[a[i]][q - 1]);
		b[i] = pos[a[i]][q];
	}
	if (cur == -1) {
		printf("0\n");
		return;
	}
	int ans = n;
	for (int i = 0; i < n; i++) {
		ans = min(ans, cur - i + 1);
		if (isRight[i]) break;
		cur = max(cur, b[i]);
	}
	printf("%d\n", ans);
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