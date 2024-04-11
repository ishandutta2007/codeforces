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

const int N = 300300;
const int LOG = 19;
int par[N][LOG];
bool bad[N];
ll a[N][2];

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = par[v][k];
	return v;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d%lld%lld", &n, &a[1][0], &a[1][1]);
	bad[0] = 1;
	for (int i = 2; i <= n + 1; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%lld%lld", &par[i][0], &a[i][0], &a[i][1]);
			par[i][0]++;
			for (int k = 0; k < LOG - 1; k++)
				par[i][k + 1] = par[par[i][k]][k];
		} else {
			int v;
			ll w;
			scanf("%d %lld", &v, &w);
			v++;
			if (bad[v]) {
				printf("0 0\n");
				fflush(stdout);
				continue;
			}
			int u = v;
			int H = 0;
			for (int k = LOG - 1; k >= 0; k--) {
				if (!bad[par[u][k]]) {
					u = par[u][k];
					H += 1 << k;
				}
			}
			ll ans1 = 0, ans2 = 0;
			while(w > 0 && H >= 0) {
				u = up(v, H);
				ll x = min(w, a[u][0]);
				a[u][0] -= x;
				bad[u] |= a[u][0] == 0;
				w -= x;
				ans1 += x;
				ans2 += x * a[u][1];
				H--;
			}
			printf("%lld %lld\n", ans1, ans2);
			fflush(stdout);
		}
	}

	return 0;
}