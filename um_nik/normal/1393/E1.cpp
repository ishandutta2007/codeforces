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


const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = (int)1e6 + 77;
int nxtDiff[3][N];
int pref[N], prefGood[N];
int ndp[N], nAdd[N], nAddGood[N];

vector<pii> getPositions(const vector<int> &s) {
	vector<pii> res = {{N, 1}};
	int cnt = 0;
	for (int i = 0; i < (int)s.size() - 1; i++) {
		cnt++;
		if (s[i + 1] != s[i]) {
			res.push_back({i, cnt});
			cnt = 0;
		}
	}
	return res;
}

void precalcDiff(const vector<int> &s, const vector<int> &p) {
	int n = (int)s.size(), m = (int)p.size();
	for (int d = 0; d < 3; d++) {
		int z = min(n, m + d - 1);
		nxtDiff[d][z] = z;
		for (int i = z - 1; i >= max(0, d - 1); i--) {
			if (s[i] == p[i - (d - 1)])
				nxtDiff[d][i] = nxtDiff[d][i + 1];
			else
				nxtDiff[d][i] = i;
		}
	}
}

bool cmp(int p, int q, const vector<int> &s, const vector<int> &t) {
	int z = nxtDiff[1][0];
	if (z < p && z < q) return s[z] < t[z];
	if (p < q) {
		z = nxtDiff[2][p + 1];
		if (z - 1 < q) return s[z] < t[z - 1];
		z = nxtDiff[1][q + 1];
		return s[z] < t[z];
	} else {
		z = nxtDiff[0][q];
		if (z < p) return s[z] < t[z + 1];
		z = nxtDiff[1][p + 1];
		return s[z] < t[z];
	}
}

vector<int> solve(const vector<int> &s, const vector<int> &p, vector<pii> a, vector<pii> b, vector<int> dp) {
	/*
	eprintf("solve\n");
	for (int x : s)
		eprintf("%d ", x);
	eprintf("\n");
	for (int x : p)
		eprintf("%d ", x);
	eprintf("\n");
	*/
	precalcDiff(s, p);
	int n = (int)s.size(), m = (int)p.size();
	for (int i = 0; i <= (int)b.size(); i++) {
		ndp[i] = nAdd[i] = nAddGood[i] = 0;
	}

	for (int i = 0; i < (int)a.size(); i++)
		for (int j = 0; j < (int)b.size(); j++)
			if (cmp(a[i].first, b[j].first, s, p))
				ndp[j] = add(ndp[j], mult(dp[i], a[i].second));

	dp = vector<int>((int)b.size());
	for (int i = 0; i < (int)b.size(); i++)
		dp[i] = ndp[i];
	return dp;
}


vector<int> a[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char c : s)
			a[i].push_back(c + N);
		a[i].push_back(i);
	}

	vector<pii> old = getPositions(a[0]);
	vector<int> dp((int)old.size(), 1);

	for (int i = 1; i < n; i++) {
		vector<pii> nw = getPositions(a[i]);
		dp = solve(a[i - 1], a[i], old, nw, dp);
		old = nw;
		/*
		eprintf("dp: ");
		for (int x : dp)
			eprintf("%d ", x);
		eprintf("\n");
		*/
	}
	int ans = 0;
	for (int i = 0; i < (int)old.size(); i++) ans = add(ans, mult(dp[i], old[i].second));
	printf("%d\n", ans);

	return 0;
}