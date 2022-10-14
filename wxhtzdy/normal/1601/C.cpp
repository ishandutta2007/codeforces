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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N = 1000050;
const int M = 32 * N;
int n, m;
int a[N];
int b[N];
int mn[M];
int lzy[M];
vector<int> pos[2 * N];

void push(int v, int l, int r) {
	if (l != r) {
		mn[v * 2] += lzy[v];
		mn[v * 2 + 1] += lzy[v];
		lzy[v * 2] += lzy[v];
		lzy[v * 2 + 1] += lzy[v];
	}
	lzy[v] = 0;
}

void build(int v, int l, int r) {
	mn[v] = 0; lzy[v] = 0;
	if (l == r) return;
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
}

void rangeAdd(int v, int l, int r, int ql, int qr, int x) {
	if (l > r || l > qr || r < ql) return;
	if (ql <= l && r <= qr) {
		mn[v] += x; lzy[v] += x; push(v, l, r);
		return;
	}
	push(v, l, r);
	int m = (l + r) / 2;
	rangeAdd(v * 2, l, m, ql, qr, x);
	rangeAdd(v * 2 + 1, m + 1, r, ql, qr, x);
	mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
}

struct Fenwick {
	vector<int> fenv;
	int n;

	Fenwick(int _n = 0) : n(_n), fenv(_n) {}
	void modify(int x, int v) {
		for (; x < n; x += x & -x)
			fenv[x] += v;
	}
	int get(int x) {
		int r = 0;
		for (; x > 0; x -= x & -x)
			r += fenv[x];
		return r;
	}
};

ll inv_cnt() {
	ll inv = 0;
	Fenwick fenv(n + m + 1);
	for (int i = n - 1; i >= 0; i--) {
		inv += fenv.get(a[i] - 1);
		fenv.modify(a[i], 1);
	}
	return inv;
}

void solve() {
	n = readint();
	m = readint();
	for (int i = 0; i < n; i++)
		a[i] = readint();
	for (int i = 0; i < m; i++)
		b[i] = readint();
	sort(b, b + m);
	build(1, 0, n);
	for (int i = 0; i < n; i++) {
		if (a[i] == b[0])
			continue;
		if (a[i] > b[0])
			rangeAdd(1, 0, n, i + 1, n, 1);
		else
			rangeAdd(1, 0, n, 0, i, 1);
	}
	vector<int> vec;
	for (int i = 0; i < n; i++) vec.pb(a[i]);
	for (int i = 0; i < m; i++) vec.pb(b[i]);
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(all(vec), a[i]) - vec.begin() + 1;
	for (int i = 0; i < m; i++)
		b[i] = lower_bound(all(vec), b[i]) - vec.begin() + 1;
	for (int i = 0; i <= n + m; i++)
		pos[i].clear();
	for (int i = 0; i < n; i++)
		pos[a[i]].push_back(i);
	ll ans = inv_cnt() + mn[1];
	for (int i = 1; i < m; i++) {
		if (b[i] == b[i - 1]) {
			ans += mn[1];
			continue;
		}
		for (int j : pos[b[i - 1]]) {
			rangeAdd(1, 0, n, 0, j, 1);
		}
		for (int x = b[i - 1] + 1; x < b[i]; x++) {
			for (int j : pos[x]) {
				rangeAdd(1, 0, n, j + 1, n, -1);
				rangeAdd(1, 0, n, 0, j, 1);
			}
		}
		for (int j : pos[b[i]]) {
			rangeAdd(1, 0, n, j + 1, n, -1);
		}
		ans += mn[1];
	}
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();

	int t;
	t = readint();
	while(t--) solve();

	return 0;
}