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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = (1 << 20) + 7;
int ord[N];
int myPos[N];
int bal[N];
int a[2 * N];
int ans[N];
int ansSz;
int n, m;

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < (1 << n); i++) {
		scanf("%d", &a[i]);
		myPos[a[i]] = i;
		ord[i - 1] = a[i];
		int v = i;
		int k = 0;
		while(v > 1) {
			v /= 2;
			k++;
		}
	}
	for (int i = (1 << n); i < (1 << (n + 1)); i++)
		a[i] = 0;
	sort(ord, ord + (1 << n) - 1);
	reverse(ord, ord + (1 << n) - 1);
	ll sum = 0;
	ansSz = 0;
	for (int i = 0; i < (1 << n) - 1; i++) {
		int x = ord[i];
		int v = myPos[x];
		while(a[v] > 0) {
			v *= 2;
			if (a[v] < a[v + 1]) v++;
		}
		v /= 2;
		if (v < (1 << m)) {
			sum += x;
			continue;
		}
		v = myPos[x];
		ans[ansSz++] = v;
		while(a[v] > 0) {
			v *= 2;
			if (a[v] < a[v + 1]) v++;
			if (a[v] > 0) myPos[a[v]] = v / 2;
			a[v / 2] = a[v];
		}
	}
	printf("%lld\n", sum);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();


	return 0;
}