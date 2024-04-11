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

const int N = 1030;
int n;
char s[N];
int Q;

vector<int> g[N];

int query() {
	Q++;
#ifdef LOCAL
	int res = 0;
	for (int i = 0; i < n; i++)
		res += (int)(s[i] == 'T');
	return res;
#else
	printf("%s\n", s);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	if (x == n) exit(0);
	return x;
#endif
}

void myFlip(int i) {
	s[i] ^= 'T' ^ 'F';
}

int X;

vector<int> AAA;

void dfs(int v, int k) {
	if (k) {
		myFlip(v);
		X++;
	}
	for (int u : g[v])
		dfs(u, k ^ 1);
}

void solve(vector<int> p, int T) {
	int sz = (int)p.size();
	//eprintf("sz = %d, T = %d\n", sz, T);
	if (T == 0) {
		X += sz;
		for (int x : p) myFlip(x);
		return;
	}
	if (T == sz) return;
	shuffle(all(p), rng);
	if (sz == 2) {
		int v = p[0], u = p[1];
		g[v].push_back(u);
		AAA.push_back(v);
		return;
	}
	vector<int> l, r;
	for (int i = 0; i < sz; i++) {
		if (i & 1)
			l.push_back(p[i]);
		else
			r.push_back(p[i]);
	}
	int LT = 0, RT = 0;
	for (int x : l) myFlip(x);
	int Y = query();
	for (int x : l) myFlip(x);
	LT = (int)l.size() - Y + X;
	assert(LT % 2 == 0);
	LT /= 2;
	assert(0 <= LT && LT <= (int)l.size());
	RT = T - LT;
	assert(0 <= RT && RT <= (int)r.size());
	solve(l, LT);
	solve(r, RT);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	precalc();

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		s[i] = 'F';
		if (myRand(2)) myFlip(i);
	}
	X = query();
	vector<int> p;
	for (int i = 0; i < n; i++)
		p.push_back(i);
	solve(p, X);
	
	p = AAA;
	while((int)p.size() >= 2) {
		int sz = (int)p.size();
		int v = myRand(sz);
		swap(p[v], p.back());
		v = p.back();
		p.pop_back();
		sz--;
		int u = myRand(sz);
		swap(p[u], p.back());
		u = p.back();
		p.pop_back();
		//eprintf("%d %d\n", v, u);
		myFlip(v);
		myFlip(u);
		int Y = query();
		myFlip(v);
		myFlip(u);
		if (Y < X) {
			dfs(v, 0);
			dfs(u, 0);
		} else if (Y > X) {
			dfs(v, 1);
			dfs(u, 1);
		} else {
			if (myRand(2)) swap(v, u);
			g[v].push_back(u);
			p.push_back(v);
		}
	}
	if (!p.empty()) {
		int v = p.back();
		myFlip(v);
		int Y = query();
		myFlip(v);
		if (Y < X) {
			dfs(v, 0);
		} else {
			dfs(v, 1);
		}
	}
	eprintf("X = %d\n", X);
	

	assert(X == n);
	query();
#ifdef LOCAL
	eprintf("Q = %d\n", Q);
#else
	assert(false);
#endif

	return 0;
}