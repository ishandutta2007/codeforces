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

const int N = (1 << 17);
struct Node {
	int l, r;
	set<pii> setik;

	Node() : l(), r(), setik() {}
	Node(int _l, int _r) : l(_l), r(_r), setik() {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void addSegm(int v, pii s) {
	v += N;
	while(v > 0) {
		auto it = tree[v].setik.lower_bound(mp(s.first, -1));
		if (it != tree[v].setik.end() && it->second <= s.second) {

		} else {
			it = tree[v].setik.lower_bound(mp(s.first + 1, -1));
			while(it != tree[v].setik.begin()) {
				it--;
				if (it->second < s.second) break;
				it = tree[v].setik.erase(it);
			}
			tree[v].setik.insert(s);
		}
		v >>= 1;
	}
}
int getLeftmost(int v, int l, int r) {
	auto it = tree[v].setik.lower_bound(mp(l, -1));
	if (it == tree[v].setik.end() || it->second > r) return -1;
	if (v >= N) return v - N;
	int res = getLeftmost(2 * v, l, r);
	if (res != -1)
		return res;
	return getLeftmost(2 * v + 1, l, r);
}

const int M = 100100;
int n, m;
int a[M][2];
pii ord[M];
int ANS[M];

int solve(int l, int r) {
	int v = getLeftmost(1, l, r);
	if (v == -1) return 0;
	return a[v][1] - a[v][0] + solve(l, a[v][0]) + solve(a[v][1], r);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		a[i][0]--;
		ord[i] = mp(a[i][1] - a[i][0], i);
	}
	sort(ord, ord + m);
	reverse(ord, ord + m);
	int pos = 0;
	for (int x = n; x > 0; x--) {
		while(pos < m && ord[pos].first >= x) {
			int v = ord[pos].second;
			addSegm(v, mp(a[v][0], a[v][1]));
			pos++;
		}
		ANS[x] = solve(0, n);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ANS[i]);

	return 0;
}