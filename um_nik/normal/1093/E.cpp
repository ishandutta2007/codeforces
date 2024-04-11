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

const int N = 1 << 18;
int a[N + 5];
int aa[N + 5];
int b[N + 5];
int n, q;
int Q[N + 5][5];

struct SNode {
	int l, r;
	vector<int> all;
	vector<int> fenv;

	SNode() : l(), r(), all(), fenv() {}
	SNode(int _l, int _r) : l(_l), r(_r), all(), fenv() {}

	void init() {
		sort(all.begin(), all.end());
		all.resize(unique(all.begin(), all.end()) - all.begin());
		fenv.resize(all.size());
		for (int i = 0; i < (int)fenv.size(); i++)
			fenv[i] = 0;
	}

	void add(int x, int d) {
		x = lower_bound(all.begin(), all.end(), x) - all.begin();
		for(; x < (int)all.size(); x |= x + 1)
			fenv[x] += d;
	}

	int getSum(int x) {
		x = lower_bound(all.begin(), all.end(), x) - all.begin() - 1;
		int sum = 0;
		for(; x >= 0; x = (x & (x + 1)) - 1)
			sum += fenv[x];
		return sum;
	}
};
SNode stree[2 * N + 7];

void build() {
	for (int i = 0; i < N; i++)
		stree[N + i] = SNode(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		stree[i] = SNode(stree[2 * i].l, stree[2 * i + 1].r);
}

void add(int v, int x, int d) {
	v += N;
	while(v > 0) {
		stree[v].add(x, d);
		v >>= 1;
	}
}
void addVec(int v, int x) {
	v += N;
	while(v > 0) {
		stree[v].all.push_back(x);
		v >>= 1;
	}
}

int getSegm(int v, int l, int r, int x1, int x2) {
	if (l <= stree[v].l && stree[v].r <= r)
		return stree[v].getSum(x2) - stree[v].getSum(x1);
	if (l >= stree[v].r || stree[v].l >= r) return 0;
	return getSegm(2 * v, l, r, x1, x2) + getSegm(2 * v + 1, l, r, x1, x2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		b[x] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] = b[a[i]];
		aa[i] = a[i];
	}
	for (int i = 0; i < n; i++)
		addVec(i, a[i]);
	for (int i = 0; i < q; i++) {
		scanf("%d", &Q[i][0]);
		if (Q[i][0] == 1) {
			for (int j = 1; j < 5; j++)
				scanf("%d", &Q[i][j]);
			Q[i][1]--;
			Q[i][3]--;
		} else {
			scanf("%d%d", &Q[i][1], &Q[i][2]);
			Q[i][1]--;
			Q[i][2]--;
			int v = Q[i][1], u = Q[i][2];
			swap(a[v], a[u]);
			addVec(v, a[v]);
			addVec(u, a[u]);
		}
	}
	for (int i = 0; i < n; i++)
		a[i] = aa[i];
	for (int i = 1; i < 2 * N; i++)
		stree[i].init();
	for (int i = 0; i < n; i++)
		add(i, a[i], 1);
	for (int i = 0; i < q; i++) {
		if (Q[i][0] == 1) {
			printf("%d\n", getSegm(1, Q[i][3], Q[i][4], Q[i][1], Q[i][2]));
		} else {
			int v = Q[i][1], u = Q[i][2];
			add(v, a[v], -1);
			add(u, a[u], -1);
			swap(a[v], a[u]);
			add(v, a[v], 1);
			add(u, a[u], 1);
		}
	}

	return 0;
}