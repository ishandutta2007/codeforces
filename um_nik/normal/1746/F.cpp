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

const ll C = (ll)1e13;
const int N = 300300;
const int K = 40;
int n, m, q;
int xs[2 * N];
int a[N];
int aa[N];
int Q[N][3];
ll h[2 * N];
bool ans[N];

struct Fenwick {
	vector<ll> fenv;

	Fenwick() : fenv() {}
	Fenwick(int n) : fenv(vector<ll>(n, 0)) {}

	void add(int p, ll x) {
		for(; p < (int)fenv.size(); p |= p + 1)
			fenv[p] += x;
	}
	ll get(int r) {
		ll res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += fenv[r];
		return res;
	}
	ll getSum(ll l, ll r) {
		if (l >= r) return 0;
		return get(r - 1) - get(l - 1);
	}
} fenv;

void read() {
	/*
	n = q = 300000;
	for (int i = 0; i < n; i++) {
		a[i] = myRand(1e6);
		xs[m++] = a[i];
	}
	for (int i = 0; i < q; i++) {
		int t = myRand(2);
		if (t == 0) {
			Q[i][0] = myRand(n);
			Q[i][1] = myRand(1e6);
			xs[m++] = Q[i][1];
			Q[i][2] = -1;
		} else {
			Q[i][0] = Q[i][1] = 0;
			while(Q[i][0] >= Q[i][1]) {
				Q[i][0] = myRand(n);
				Q[i][1] = myRand(n);
			}
			Q[i][2] = 1 + myRand(n);
		}
	}
	*/
	
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		xs[m++] = a[i];
	}
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &Q[i][0], &Q[i][1]);
			Q[i][0]--;
			xs[m++] = Q[i][1];
			Q[i][2] = -1;
		} else {
			scanf("%d%d%d", &Q[i][0], &Q[i][1], &Q[i][2]);
			Q[i][0]--;
		}
	}
	
	sort(xs, xs + m);
	m = unique(xs, xs + m) - xs;
	for (int i = 0; i < n; i++)
		aa[i] = lower_bound(xs, xs + m, a[i]) - xs;
	for (int i = 0; i < q; i++)
		if (Q[i][2] == -1)
			Q[i][1] = lower_bound(xs, xs + m, Q[i][1]) - xs;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int i = 0; i < q; i++)
		ans[i] = 1;
	fenv = Fenwick(n);
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < n; i++)
			a[i] = aa[i];
		for (int i = 0; i < m; i++)
			h[i] = myRand(C);
		for (int i = 0; i < n; i++)
			fenv.fenv[i] = 0;
		for (int i = 0; i < n; i++)
			fenv.add(i, h[a[i]]);
		for (int i = 0; i < q; i++) {
			if (Q[i][2] == -1) {
				int p = Q[i][0];
				int x = Q[i][1];
				fenv.add(p, h[x] - h[a[p]]);
				a[p] = x;
			} else {
				ans[i] &= fenv.getSum(Q[i][0], Q[i][1]) % Q[i][2] == 0;
			}
		}
	}
	for (int i = 0; i < q; i++) if (Q[i][2] != -1) {
		if (ans[i])
			printf("YES\n");
		else
			printf("NO\n");
	}


	return 0;
}