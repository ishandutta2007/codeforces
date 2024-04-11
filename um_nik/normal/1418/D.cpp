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

set<int> pts;
multiset<int> segm;

void add(int x) {
	assert(pts.count(x) == 0);
	auto it = pts.lower_bound(x);
	if (it != pts.end() && it != pts.begin()) {
		int len = *it - *prev(it);
		segm.erase(segm.find(len));
	}
	if (it != pts.end()) {
		segm.insert(*it - x);
	}
	if (it != pts.begin()) {
		segm.insert(x - *prev(it));
	}
	pts.insert(x);
}
void rem(int x) {
	assert(pts.count(x) == 1);
	auto it = pts.lower_bound(x);
	int l = -1, r = -1;
	it++;
	if (it != pts.end()) {
		r = *it;
	}
	it--;
	if (it != pts.begin()) {
		it--;
		l = *it;
	}
	if (l != -1) segm.erase(segm.find(x - l));
	if (r != -1) segm.erase(segm.find(r - x));
	if (l != -1 && r != -1) segm.insert(r - l);
	pts.erase(x);
}

int getAns() {
	if ((int)pts.size() <= 1) return 0;
	return *pts.rbegin() - *pts.begin() - *segm.rbegin();
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		add(x);
	}
	printf("%d\n", getAns());
	while(q--) {
		int t, x;
		scanf("%d%d", &t, &x);
		if (t == 1)
			add(x);
		else
			rem(x);
		printf("%d\n", getAns());
	}

	return 0;
}