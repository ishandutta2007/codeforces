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

const int N = 100050;
const int LOG = 50;
int n;
ll k;
int p[N][LOG];
ll s[N][LOG];
ll m[N][LOG];

int main() 
{
	startTime = clock();

	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i][0]), p[i][0]++;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i][0]);
		m[i][0] = s[i][0];
	}
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			s[i][j] = s[i][j - 1] + s[p[i][j - 1]][j - 1];
			m[i][j] = min(m[i][j - 1], m[p[i][j - 1]][j - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		ll S = 0, M = (ll)1e18;
		int u = i;
		for (int j = LOG - 1; j >= 0; j--) {
			if (k & (1ll << j)) {
				S += s[u][j];
				M = min(M, m[u][j]);
				u = p[u][j];
			}
		}
		printf("%lld %lld\n", S, M);
	}

	return 0;
}