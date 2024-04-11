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

const ll INF = (ll)1e14;
const int N = 100100;
const int A = 26;
int n;
char s[N], t[N];
vector<int> forPos[N];

struct Fenwick {
	vector<int> fenv;

	Fenwick() : fenv() {}
	Fenwick(int n) : fenv(vector<int>(n, 0)) {}

	void add(int p, int x) {
		for(; p < (int)fenv.size(); p |= p + 1)
			fenv[p] += x;
	}
	int get(int r) {
		int res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += fenv[r];
		return res;
	}
	int getSum(int l, int r) {
		if (l >= r) return 0;
		return get(r - 1) - get(l - 1);
	}
} fenv;

void solve() {
	ll ans = INF;
	scanf("%d %s %s", &n, s, t);
	for (int i = 0; i < A; i++)
		forPos[i].clear();
	for (int i = 0; i < n; i++)
		forPos[(int)(s[i] - 'a')].push_back(i);
	for (int i = 0; i < A; i++)
		reverse(all(forPos[i]));
	fenv = Fenwick(n);
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		int c = (int)(t[i] - 'a');
		int m = n;
		for (int d = 0; d < c; d++) {
			if (forPos[d].empty()) continue;
			m = min(m, forPos[d].back());
		}
		if (m < n) {
			ans = min(ans, cur + m - fenv.get(m));
		}
		if (forPos[c].empty()) break;
		m = forPos[c].back();
		forPos[c].pop_back();
		cur += m - fenv.get(m);
		fenv.add(m, 1);
	}
	if (ans == INF) ans = -1;
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	while(q--) solve();

	return 0;
}