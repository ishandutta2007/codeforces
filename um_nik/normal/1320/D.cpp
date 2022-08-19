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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 1 << 18;
ll pw[N + 5];
struct Item {
	int cnt;
	ll h;
	int x, y;

	Item() : cnt(-1), h(0), x(0), y(0) {}
	Item(int _cnt, ll _h, int _x, int _y) : cnt(_cnt), h(_h), x(_x), y(_y) {}

	Item operator + (const Item &I) const {
		if (cnt == -1) return I;
		if (I.cnt == -1) return *this;
		Item R = Item(cnt + I.cnt, add(h, mult(I.h, pw[cnt])), x, I.y);
		if (y && I.x) R.h = sub(R.h, mult(2, pw[cnt]));
		if (cnt == 0) {
			if (I.cnt == 0) {
				int w = x ^ I.x;
				return Item(0, w, w, w);
			}
			R.x = x ^ I.x;
		} else if (I.cnt == 0) {
			R.y = y ^ I.y;
		}
		return R;
	}

	bool operator == (const Item &I) const {
		return cnt == I.cnt && h == I.h && x == I.x && y == I.y;
	}

	void eprint() {
		eprintf("cnt = %d, h = %lld, x = %d, y = %d\n", cnt, h, x, y);
	}
};

Item ZERO = Item(1, 0, 0, 0);
Item ONE = Item(0, 1, 1, 1);

struct Node {
	int l, r;
	Item val;

	Node() : l(), r(), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val() {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void setPoint(int v, Item I) {
	v += N;
	tree[v].val = I;
	while(v > 1) {
		v >>= 1;
		tree[v].val = tree[2 * v].val + tree[2 * v + 1].val;
	}
}
Item getSegm(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return Item();
	return getSegm(2 * v, l, r) + getSegm(2 * v + 1, l, r);
}

char s[N + 5];
int n, q;

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	pw[0] = 1;
	pw[1] = 37;
	for (int i = 2; i < N; i++)
		pw[i] = mult(pw[i - 1], pw[1]);

	scanf("%d", &n);
	scanf("%s", s);

	build();
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			setPoint(i, ZERO);
		} else {
			setPoint(i, ONE);
		}
	}

	scanf("%d", &q);
	while(q--) {
		int p1, p2, len;
		scanf("%d%d%d", &p1, &p2, &len);
		p1--;
		p2--;
		Item I1 = getSegm(1, p1, p1 + len);
		Item I2 = getSegm(1, p2, p2 + len);
//		I1.eprint();
//		I2.eprint();
		if (I1 == I2) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}