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

const ll INF = (ll)4e18;
const int N = 100100;
int n;
ll k;
ll a[N];
ll b[N];

void solve(ll d) {
	for (int i = 0; i < n; i++) {
		if (a[i] <= d) {
			b[i] = 0;
			continue;
		}
		b[i] = (ll)sqrtl((ld)(a[i] - d) / 3);
		while(b[i] > 0 && a[i] - 3 * b[i] * b[i] < d) b[i]--;
		while(a[i] - 3 * b[i] * b[i] > d) b[i]++;
		b[i] = min(b[i], a[i]);
	}
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll l = -INF, r = INF;
	while(r - l > 1) {
		ll mid = l + (r - l) / 2;
		solve(mid);
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += b[i];
		if (sum <= k)
			r = mid;
		else
			l = mid;
	}
	solve(r);
	for (int i = 0; i < n; i++)
		k -= b[i];
	for (int i = 0; k > 0 && i < n; i++) {
		if (b[i] == a[i]) continue;
		if (a[i] - 3 * b[i] * b[i] == r) {
			b[i]++;
			k--;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", b[i]);
	printf("\n");

	return 0;
}