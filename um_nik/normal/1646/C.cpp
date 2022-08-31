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

const ll INF = (ll)1e12 + 3;
vector<ll> f;

int solve() {
	ll n;
	scanf("%lld", &n);
	int ans = __builtin_popcountll(n);
	for (int mask = 0; mask < (1 << (int)f.size()); mask++) {
		int res = 0;
		ll cur = n;
		for (int i = 0; i < (int)f.size(); i++) {
			if (((mask >> i) & 1) == 0) continue;
			res++;
			cur -= f[i];
		}
		if (cur < 0) continue;
		res += __builtin_popcountll(cur);
		ans = min(ans, res);
	}
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll c = 6;
	ll nxt = 4;
	while(c < INF) {
		f.push_back(c);
		c *= nxt;
		nxt++;
	}
	int t;
	scanf("%lld", &t);
	while(t--) printf("%d\n", solve());

	return 0;
}