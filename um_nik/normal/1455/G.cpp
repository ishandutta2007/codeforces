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

const ll INF = (ll)1e18;

struct DP {
	map<int, ll> toVal;
	set<pli> byValue;
	ll toAdd;

	DP() : toVal(), byValue(), toAdd(0) {}

	ll getVal(int key) {
		if (toVal.count(key) == 0) return INF;
		return toVal[key] + toAdd;
	}
	void setVal(int key, ll val) {
		ll oldVal = getVal(key);
		if (val < oldVal) {
			val -= toAdd;
			if (oldVal != INF)
				byValue.erase(mp(oldVal - toAdd, key));
			toVal[key] = val;
			byValue.insert(mp(val, key));
		}
	}
	ll getMin() {
		if (byValue.empty()) return INF;
		return byValue.begin()->first + toAdd;
	}

	void del(int key) {
		if (toVal.count(key) == 0) return;
		ll val = toVal[key];
		toVal.erase(key);
		byValue.erase(mp(val, key));
	}
};

DP* merge(DP* V, DP* U) {
	if (V->byValue.size() < U->byValue.size()) swap(V, U);
	for (auto t : U->toVal) {
		V->setVal(t.first, t.second + U->toAdd);
	}
	return V;
}

const int N = 200200;
int n, s;
int a[N][3];
int pr[N];
int st[N];
int stSz;
char sss[11];

DP* solve(int L, int R, DP* V) {
	while(L < R) {
		if (a[L][0] == 0) {
			int key = a[L][1];
			ll cost = a[L][2];
			ll minVal = V->getMin();
			V->toAdd += cost;
			if (key != s)
				V->setVal(key, minVal);
			L++;
		} else {
			int key = a[L][1];
			assert(pr[L] < R);
			ll oldVal = V->getVal(key);
			if (oldVal == INF) {
				L = pr[L] + 1;
				continue;
			}
			V->del(key);
			DP* U = new DP();
			U->setVal(key, oldVal);
			U = solve(L + 1, pr[L], U);
			V = merge(V, U);
			L = pr[L] + 1;
		}
	}
	return V;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		pr[i] = -1;
		scanf("%s", sss);
		if (sss[0] == 's') {
			a[i][0] = 0;
			scanf("%d%d", &a[i][1], &a[i][2]);
		} else if (sss[0] == 'i') {
			a[i][0] = 1;
			scanf("%d", &a[i][1]);
		} else {
			a[i][0] = 2;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i][0] == 0) continue;
		if (a[i][0] == 1) {
			st[stSz++] = i;
		} else {
			assert(stSz > 0);
			stSz--;
			pr[i] = st[stSz];
			pr[st[stSz]] = i;
		}
	}
	assert(stSz == 0);

	DP* V = new DP();
	V->setVal(0, 0);
	V = solve(0, n, V);
	printf("%lld\n", V->getMin());

	return 0;
}