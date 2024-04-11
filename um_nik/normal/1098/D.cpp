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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 30;
ll mn[K][2];
ll sum[K];
multiset<int> setik[K];
int sz = 0;

void recalcMin(int k) {
	if (setik[k].empty()) return;
	auto it = setik[k].begin();
	for (int i = 0; i < 2; i++) {
		if (it == setik[k].end()) return;
		mn[k][i] = *it;
		it++;
	}
}
void addOne(int x) {
	sz++;
	int k = 0;
	while((1 << (k + 1)) <= x) k++;
	sum[k] += x;
	setik[k].insert(x);
	recalcMin(k);
}
void remOne(int x) {
	sz--;
	int k = 0;
	while((1 << (k + 1)) <= x) k++;
	sum[k] -= x;
	setik[k].erase(setik[k].find(x));
	recalcMin(k);
}

int answer() {
	if (sz == 0) return 0;
	int ans = sz - 1;
	ll S = 0;
	for (int i = 0; i < K; i++) {
		ll SS = S + sum[i];
		int bn = (int)setik[i].size();
		bn = min(bn, 2);
		for (int j = 0; j < bn; j++) {
			if (S > 0 && 2 * S < mn[i][j]) ans--;
			S += mn[i][j];
		}
		S = SS;
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	while(q--) {
		char t;
		int x;
		scanf(" %c %d", &t, &x);
		if (t == '+')
			addOne(x);
		else
			remOne(x);
		printf("%d\n", answer());
	}

	return 0;
}