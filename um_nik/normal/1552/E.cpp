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

const int N = (int)1e4 + 55;
const int K = 103;
int n, k;
int a[N];
pii b[K][K];
int p[K][K];
int cnt[K];
pii ans[K];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n * k; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		p[cnt[a[i]]][a[i]] = i;
		b[cnt[a[i]]][a[i]] = mp(i, a[i]);
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++)
		assert(cnt[i] == k);
	for (int i = 0; i < n; i++)
		ans[i] = mp(-1, -1);
	for (int i = 0; i < k; i++)
		sort(b[i], b[i] + n);
	int d = (n + k - 2) / (k - 1);
	int l = 0;
	for (int it = 1; l < n; it++) {
		assert(it < k);
		int w = min(n - l, d);
		for (int i = 0; w > 0; i++) {
			assert(i < n);
			int c = b[it][i].second;
			if (ans[c].first != -1) continue;
			w--;
			ans[c] = mp(p[it - 1][c], p[it][c]);
		}
		l += d;
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);

	return 0;
}