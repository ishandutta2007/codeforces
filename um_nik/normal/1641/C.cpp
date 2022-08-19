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

const int N = (1 << 18);
struct Node {
	int l, r, val;
	vector<pii> a;

	Node() : l(), r(), val(), a() {}
	Node(int _l, int _r) : l(_l), r(_r), val(_r - _l), a() {}
};
Node tree[2 * N + 5];
void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
int getOnly(int v, int l, int r) {
	if (l >= tree[v].r || tree[v].l >= r) return -1;
	if (tree[v].val == 0) return -1;
	if (l <= tree[v].l && tree[v].r <= r && tree[v].val > 1) return -2;
	if (v >= N) return tree[v].l;
	int res1 = getOnly(2 * v, l, r), res2 = getOnly(2 * v + 1, l, r);
	if (res1 == -1) return res2;
	if (res2 == -1) return res1;
	return -2;
}
int ans[N + 5];
void check(int l, int r) {
	int v = getOnly(1, l, r);
	if (v >= 0) ans[v] = 1;
}
void addPoint(int v, int x) {
	v += N;
	while(v >= 1) {
		tree[v].val += x;
		if (tree[v].val <= 1) {
			for (pii s : tree[v].a) check(s.first, s.second);
		}
		v >>= 1;
	}
}
void addSegm(int v, int l, int r, pii x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].a.push_back(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	addSegm(2 * v, l, r, x);
	addSegm(2 * v + 1, l, r, x);
}

set<int> setik;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		setik.insert(i);
		ans[i] = -1;
	}
	build();
	while(q--) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l--;
			if (x == 0) {
				while(true) {
					auto it = setik.lower_bound(l);
					if (it == setik.end() || *it >= r) break;
					int x = *it;
					setik.erase(it);
					addPoint(x, -1);
					ans[x] = 0;
				}
			} else {
				check(l, r);
				addSegm(1, l, r, mp(l, r));
			}
		} else {
			int v;
			scanf("%d", &v);
			v--;
			if (ans[v] == -1) {
				printf("N/A\n");
			} else if (ans[v] == 0) {
				printf("NO\n");
			} else {
				printf("YES\n");
			}
		}
	}

	return 0;
}