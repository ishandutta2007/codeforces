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

const int N = 250250;
const int LOG = 18;
int n;
int a[N];
pii sparseMin[LOG][N];
pii sparseMax[LOG][N];
int p2[N];
int st[N];
int nxtSmaller[N], nxtBigger[N];

pii getMin(int l, int r) {
	int k = p2[r - l];
	return min(sparseMin[k][l], sparseMin[k][r - (1 << k)]);
}
pii getMax(int l, int r) {
	int k = p2[r - l];
	return max(sparseMax[k][l], sparseMax[k][r - (1 << k)]);
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sparseMin[0][i] = mp(a[i], i);
		sparseMax[0][i] = mp(a[i], i);
	}
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i + (1 << (k + 1)) <= n; i++) {
			sparseMin[k + 1][i] = min(sparseMin[k][i], sparseMin[k][i + (1 << k)]);
			sparseMax[k + 1][i] = max(sparseMax[k][i], sparseMax[k][i + (1 << k)]);
		}
	int sz = 0;
	a[n] = n + 1;
	st[0] = n;
	for (int i = n - 1; i >= 0; i--) {
		while(a[st[sz]] < a[i]) sz--;
		nxtBigger[i] = st[sz];
		st[++sz] = i;
	}
	sz = 0;
	a[n] = -1;
	st[0] = n;
	for (int i = n - 1; i >= 0; i--) {
		while(a[st[sz]] > a[i]) sz--;
		nxtSmaller[i] = st[sz];
		st[++sz] = i;
	}
	
	int ans = 0;
	int p = 0;
	while(p < n - 1) {
		ans++;
		if (a[p] < a[p + 1]) {
			int q = nxtSmaller[p];
			pii t = getMax(p, q);
			p = t.second;
		} else {
			int q = nxtBigger[p];
			pii t = getMin(p, q);
			p = t.second;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}