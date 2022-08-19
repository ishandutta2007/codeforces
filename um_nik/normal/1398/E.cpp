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

set<int> small, big;
set<int> fire, elec;
ll sumBig = 0;
ll sumAll = 0;

void addOne(int x) {
	sumAll += x;
	if (big.empty() || x < *big.begin()) {
		small.insert(x);
	} else {
		big.insert(x);
		sumBig += x;
	}
}
void remOne(int x) {
	sumAll -= x;
	if (small.count(x)) {
		small.erase(x);
	} else {
		big.erase(x);
		sumBig -= x;
	}
}

ll calcAns() {
	while((int)big.size() > (int)elec.size()) {
		int x = *big.begin();
		big.erase(x);
		small.insert(x);
		sumBig -= x;
	}
	while((int)big.size() < (int)elec.size()) {
		int x = *small.rbegin();
		small.erase(x);
		big.insert(x);
		sumBig += x;
	}
	ll ans = sumAll + sumBig;
	if ((int)elec.size() > 0 && (fire.empty() || *fire.rbegin() < *elec.begin())) {
		ans -= *elec.begin();
		if (!fire.empty()) ans += *fire.rbegin();
	}
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	while(q--) {
		int t, x;
		scanf("%d%d", &t, &x);
		if (x > 0) {
			if (t == 0)
				fire.insert(x);
			else
				elec.insert(x);
			addOne(x);
		} else {
			x *= -1;
			if (t == 0)
				fire.erase(x);
			else
				elec.erase(x);
			remOne(x);
		}
		printf("%lld\n", calcAns());
	}

	return 0;
}