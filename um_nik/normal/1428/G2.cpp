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

const ll INF = (ll)1e17;

struct MaxStack {
	vector<ll> val, mx;

	MaxStack() : val(), mx() {}

	bool empty() {
		return val.empty();
	}
	ll getMax() {
		if (empty()) return -INF;
		return mx.back();
	}
	void push(ll x) {
		val.push_back(x);
		if (mx.empty())
			mx.push_back(x);
		else
			mx.push_back(max(mx.back(), x));
	}
	ll pop() {
		assert(!empty());
		ll x = val.back();
		val.pop_back();
		mx.pop_back();
		return x;
	}
};
struct MaxQueue {
	MaxStack A, B;

	MaxQueue() : A(), B() {}

	void push(ll x) {
		A.push(x);
	}
	void pop() {
		if (B.empty()) {
			while(!A.empty()) {
				B.push(A.pop());
			}
		}
		assert(!B.empty());
		B.pop();
	}
	ll getMax() {
		return max(A.getMax(), B.getMax());
	}
};

const int N = (int)1e6 + 7;
ll dp[N], old[N];
int k;

void solve(int L, ll F) {
	for (int i = 0; i < L; i++) {
		old[i] = dp[i];
		dp[i] = 0;
	}
	MaxQueue Q[3];
	for (int i = 0; i < 3; i++)
		Q[i] = MaxQueue();
	for (int x = 0; x < 10 * L; x++) {
		if (x % 10 == 0)
			Q[(x / 10) % 3].push(old[x / 10] - F * 10 * (x / 30));
		for (int y = 9 * (k - 1); y <= 9 * k; y++) {
			if (x < y) continue;
			if ((x - y) % 10 != 0) continue;
			ll val = old[(x - y) / 10];
			val += 3 * F * (k - 1);
			int z = y - 9 * (k - 1);
			if (z % 3 == 0) val += F * (z / 3);
			dp[x] = max(dp[x], val);
		}
		for (int i = 0; i < 3; i++) {
			ll val = Q[i].getMax();
			if (val < -INF / 2) continue;
			int z = x - 10 * i;
			assert(z >= 0);
			val += F * (z / 3);
			dp[x] = max(dp[x], val);
		}
		if (x >= 9 * (k - 1) && (x - 9 * (k - 1)) % 10 == 0) {
			int y = x - 9 * (k - 1);
			Q[(y / 10) % 3].pop();
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll F[6];
	scanf("%d", &k);
	for (int i = 0; i < 6; i++)
		scanf("%lld", &F[i]);
	int L = 1;
	for (int i = 5; i >= 0; i--) {
		solve(L, F[i]);
		L *= 10;
	}

	int t;
	scanf("%d", &t);
	while(t--) {
		int x;
		scanf("%d", &x);
		printf("%lld\n", dp[x]);
	}

	return 0;
}