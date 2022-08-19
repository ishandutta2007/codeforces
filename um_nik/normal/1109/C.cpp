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

struct Node {
	int L, R;
	int t, y;
	ll s;
	ll sumToLast, minSum, firstT, lastT, lastS;

	Node() : L(-1), R(-1), t(), y(rng()), s(), sumToLast(), minSum(), firstT(), lastT(), lastS() {}
};
const int N = 100100;
int treeSz;
Node tree[N];

int getNode() {
	return treeSz++;
}
int update(int v) {
	if (v == -1) return -1;
	ll sumToLast = 0, minSum = 0;
	ll firstT = tree[v].t, lastT = tree[v].t, lastS = tree[v].s;
	if (tree[v].L != -1) {
		int tL = tree[v].L;
		minSum = min(minSum, sumToLast + tree[tL].minSum);
		sumToLast += tree[tL].sumToLast;
		firstT = tree[tL].firstT;
		sumToLast += (tree[v].t - tree[tL].lastT) * tree[tL].lastS;
		minSum = min(minSum, sumToLast);
	}
	if (tree[v].R != -1) {
		int tR = tree[v].R;
		sumToLast += (tree[tR].firstT - tree[v].t) * tree[v].s;
		minSum = min(minSum, sumToLast);
		minSum = min(minSum, sumToLast + tree[tR].minSum);
		sumToLast += tree[tR].sumToLast;
		lastT = tree[tR].lastT;
		lastS = tree[tR].lastS;
	}
	tree[v].sumToLast = sumToLast;
	tree[v].minSum = minSum;
	tree[v].firstT = firstT;
	tree[v].lastT = lastT;
	tree[v].lastS = lastS;
	return v;
}

int merge(int L, int R) {
	if (L == -1) return R;
	if (R == -1) return L;
	if (tree[L].y > tree[R].y) {
		tree[L].R = merge(tree[L].R, R);
		return update(L);
	} else {
		tree[R].L = merge(L, tree[R].L);
		return update(R);
	}
}
void split(int v, int t, int &L, int &R) {
	if (v == -1) {
		L = R = -1;
		return;
	}
	if (tree[v].t >= t) {
		split(tree[v].L, t, L, tree[v].L);
		R = update(v);
	} else {
		split(tree[v].R, t, tree[v].R, R);
		L = update(v);
	}
}

void printAns(int v, ll w, ll t, ll r) {
	if (w <= 0) {
		printf("%lld\n", t);
		return;
	}
	//	eprintf("in printAns\n");
	if (v == -1) {
		printf("-1\n");
		return;
	}
	while(true) {
		if (w + tree[v].minSum > 0) {
			w += tree[v].sumToLast;
			//eprintf("w = %lld, s = %lld\n", w, tree[v].lastS);
			t = tree[v].lastT;
			if (w + (r - t) * tree[v].lastS > 0) {
				printf("-1\n");
				return;
			}
			double tm = (double)w / (-tree[v].lastS);
			printf("%.12lf\n", t + tm);
			return;
		}
		if (tree[v].L != -1) {
			int tL = tree[v].L;
			if (w + tree[tL].minSum <= 0) {
				v = tL;
				continue;
			}
			w += tree[tL].sumToLast;
			if (w + (tree[v].t - tree[tL].lastT) * tree[tL].lastS <= 0) {
				double tm = (double)w / (-tree[tL].lastS);
				printf("%.12lf\n", tree[tL].lastT + tm);
				return;
			}
			w += (tree[v].t - tree[tL].lastT) * tree[tL].lastS;
		}
		if (tree[v].R == -1) throw;
		int tR = tree[v].R;
		if (w + (tree[tR].firstT - tree[v].t) * tree[v].s <= 0) {
			double tm = (double)w / (-tree[v].s);
			printf("%.12lf\n", tree[v].t + tm);
			return;
		}
		w += (tree[tR].firstT - tree[v].t) * tree[v].s;
		t = tree[tR].firstT;
		v = tR;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int root = -1;

	int q;
	scanf("%d", &q);
	while(q--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int t, s;
			scanf("%d%d", &t, &s);
			int L, R;
			split(root, t, L, R);
			int v = getNode();
			tree[v].t = t;
			tree[v].s = s;
			v = update(v);
			root = merge(merge(L, v), R);
		} else if (tp == 2) {
			int t;
			scanf("%d", &t);
			int L, M, R;
			split(root, t, L, M);
			split(M, t + 1, M, R);
			root = merge(L, R);
		} else {
			int l, r;
			ll w;
			scanf("%d%d%lld", &l, &r, &w);
			int L, M, R;
			split(root, l, L, M);
			split(M, r, M, R);

			printAns(M, w, l, r);

			root = merge(merge(L, M), R);
		}
	}

	return 0;
}