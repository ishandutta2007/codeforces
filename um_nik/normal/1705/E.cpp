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

const int N = 300300;
set<pii> setik;

void add(int p) {
	auto it = setik.upper_bound(mp(p, N));
	if (it == setik.begin()) {
		setik.insert(mp(p, p + 1));
		return;
	}
	it--;
	if (it->first <= p && it->second > p) {
		int l = it->first;
		int r = it->second;
		setik.erase(it);
		if (l < p) setik.insert(mp(l, p));
		add(r);
	} else {
		setik.insert(mp(p, p + 1));
		return;
	}
}
void rem(int p) {
	auto it = setik.upper_bound(mp(p, N));
	if (it == setik.begin()) {
		assert(!setik.empty());
		int l = setik.begin()->first;
		int r = setik.begin()->second;
		setik.erase(setik.begin());
		setik.insert(mp(p, l));
		if (l + 1 < r) setik.insert(mp(l + 1, r));
		return;
	}
	it--;
	if (it->first <= p && it->second > p) {
		int l = it->first;
		int r = it->second;
		setik.erase(it);
		if (l < p) setik.insert(mp(l, p));
		if (p + 1 < r) setik.insert(mp(p + 1, r));
	} else {
		it++;
		int l = it->first;
		int r = it->second;
		setik.erase(it);
		setik.insert(mp(p, l));
		if (l + 1 < r) setik.insert(mp(l + 1, r));
		return;
	}
}

int a[N];
int n, q;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		add(a[i]);
	}
	while(q--) {
		int p;
		scanf("%d", &p);
		p--;
		rem(a[p]);
		scanf("%d", &a[p]);
		add(a[p]);
		printf("%d\n", setik.rbegin()->second - 1);
	}

	return 0;
}