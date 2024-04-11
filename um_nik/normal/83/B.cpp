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

const ll INF = (ll)1e9 + 7;
const int N = 300300;
int n;
ll k;
ll a[N];
vector<int> ans1, ans2;

ll count(ll x) {
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += min(x, a[i]);
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	ll l = 0, r = INF;
	while(r - l > 1) {
		ll mid = (l + r) / 2;
		if (count(mid) < k)
			l = mid;
		else
			r = mid;
	}
	if (r == INF) {
		printf("-1\n");
		return 0;
	}
	k -= count(l);
	for (int i = 0; i < n; i++) {
		if (a[i] <= l) continue;
		if (k == 0) {
			ans2.push_back(i + 1);
		} else {
			k--;
			if (a[i] > r)
				ans1.push_back(i + 1);
		}
	}
	for (int x : ans2)
		printf("%d ", x);
	for (int x : ans1)
		printf("%d ", x);
	printf("\n");

	return 0;
}