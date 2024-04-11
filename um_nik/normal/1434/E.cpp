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

const int N = 100010;
const int B = 460;
int n;
int a[N];
int c[N][B];
int rr[B][N];
int nxt[N];
pii st[B];
int stSz;

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

void addStack(int y, int x) {
	if (stSz == 0 || y > st[stSz - 1].first) {
		st[stSz++] = mp(y, x);
	} else {
		st[stSz - 1].second = x;
	}
}

inline int getNext(int x, int p) {
	if (rr[x][p] == p) return p;
	return rr[x][p] = getNext(x, rr[x][p]);
}

void setOnSegm(int x, int l, int r, int val) {
//	eprintf("setOnSegm %d %d %d %d\n", x, l, r, val);
	l = max(l, 0);
	int p = nxt[l];
	while(true) {
		p = getNext(x, p);
		if (p >= n || a[p] >= r) break;
//		eprintf("p = %d\n", p);
		c[p][x] = 2 * a[p] - val;
		rr[x][p] = p + 1;
	}
}

int solve() {
	int z = 0;
	for (int i = 0; i < n; i++) {
		while(z <= a[i]) {
			nxt[z++] = i;
		}
	}
	while(z < N) {
		nxt[z++] = n;
	}
	for (int x = 0; x < B; x++)
		for (int i = 0; i <= n; i++) {
			rr[x][i] = i;
			c[i][x] = N;
		}
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		//eprintf("i = %d\n", i);
		stSz = 0;
		addStack(-1, 0);
		for (int x = 1; x <= ans; x++) {
			if (c[i][x - 1] < a[i])
				addStack(c[i][x - 1], x);
			else
				break;
		}
		/*
		for (int j = 0; j < stSz; j++)
			eprintf("(%d %d) ", st[j].first, st[j].second);
		eprintf("\n");
		*/
		st[stSz++] = mp(a[i], N);
		for (int j = 0; j + 1 < stSz; j++) {
			int x = st[j].second;
			int l = st[j].first + 1, r = st[j + 1].first + 1;
			ans = max(ans, x + 1);
			setOnSegm(x, l, r, a[i]);
		}
	}
	return ans;
}

int dp[B][B];
int MEX(vector<int> z) {
	sort(all(z));
	z.resize(unique(all(z)) - z.begin());
	for (int i = 0;; i++)
		if (i >= (int)z.size() || z[i] != i)
			return i;
}
int stupid() {
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j >= i; j--) {
			vector<int> zz;
			for (int h = j + 1; h < n; h++) {
				if (a[j] - a[i] >= a[h] - a[j]) continue;
				zz.push_back(dp[j][h]);
			}
			dp[i][j] = MEX(zz);
		}
	vector<int> zz;
	for (int i = 0; i < n; i++)
		zz.push_back(dp[i][i]);
	return MEX(zz);
}

void gen() {
	n = 5 + myRand(100);
	while(true) {
		for (int i = 0; i < n; i++)
			a[i] = myRand(10000);
		sort(a, a + n);
		bool ok = true;
		for (int i = 1; i < n; i++)
			ok &= a[i] != a[i - 1];
		if (ok) break;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
/*
	for (int it = 0; it < 100000; it++) {
		if (it % 1000 == 0) eprintf("%d\n", it);
		gen();
		if (solve() != stupid()) throw;
	}
*/
	int q;
	scanf("%d", &q);
	int ans = 0;
	while(q--) {
		read();
		int res = solve();
//		int st = stupid();
//		eprintf("res = %d, st = %d\n", res, st);
		ans ^= res;
	}
	if (ans)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}