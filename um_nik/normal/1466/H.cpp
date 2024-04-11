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


const ll MOD = (ll)1e9 + 7;
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

const int M = (int)2.3e5;
const int N = 41;
int C[N][N];
int f[N], rf[N];
int prec[N][N][N];
int n;
vector<pii> toVec[M];
map<vector<pii>, int> toId;
int remOne[M][N];
pii bySum[M];
int dp[M][N];
int m = 0;
int getId(vector<pii> p) {
	if (toId.count(p) == 0) {
		toId[p] = m;
		toVec[m] = p;
		return m++;
	}
	return toId[p];
}

void brute(vector<pii> p, int lst, int sum) {
	int v = getId(p);
	bySum[v] = mp(sum, v);
	for (int x = lst; x + sum <= n; x++) {
		for (int k = 1; sum + k * x <= n; k++) {
			p.push_back(mp(x, k));
			brute(p, x + 1, sum + x * k);
			p.pop_back();
		}
	}
}

void precalc() {
	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	for (int g = 1; g < N; g++) {
		prec[g][0][0] = bin_pow(f[n - 1], g);
		for (int x = 1; x < N; x++)
			for (int y = x; g + y <= n; y++) {
				int A = 0, B = 0;
				for (int k = 0; k <= y; k++)
					A = add(A, mult(C[y][k], mult(f[k], f[n - 1 - k])));
				for (int k = 0; k <= y - x; k++)
					B = add(B, mult(C[y - x][k], mult(f[k], f[n - 1 - k])));
				prec[g][x][y] = sub(bin_pow(A, g), bin_pow(B, g));
			}
	}
	brute({}, 1, 0);
	eprintf("m = %d\n", m);
	eprintf("time = %.5lf\n", getCurrentTime());
	for (int id = 0; id < m; id++) {
		for (int x = 0; x <= n; x++)
			remOne[id][x] = -1;
		for (int i = 0; i < (int)toVec[id].size(); i++) {
			if (i != 0 && toVec[id][i] == toVec[id][i - 1]) continue;
			vector<pii> p = toVec[id];
			p[i].second--;
			if (p[i].second == 0)
				p.erase(p.begin() + i);
			remOne[id][toVec[id][i].first] = getId(p);
		}
	}
	eprintf("time = %.5lf\n", getCurrentTime());
}

int read() {
	vector<int> p(n);
	map<int, int> res;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (p[i] == -1) continue;
		int v = i;
		int len = 0;
		while(p[v] != -1) {
			len++;
			int u = p[v];
			p[v] = -1;
			v = u;
		}
		res[len]++;
	}
	vector<pii> rr;
	for (auto t : res) {
		eprintf("(%d %d) ", t.first, t.second);
		rr.push_back(t);
	}
	eprintf("\n");
	return getId(rr);
}

void brute2(int pos, int oldId, int newId, int X, int Y, int val, int nX) {
	if (pos == (int)toVec[oldId].size()) {
		if (nX == 0) return;
		dp[newId][nX] = add(dp[newId][nX], val);
		return;
	}
	int z = toVec[oldId][pos].first;
	for (int k = 0; k <= toVec[oldId][pos].second; k++) {
		if (k != 0) {
			newId = remOne[newId][z];
			nX += z;
			val = mult(val, prec[z][X][Y]);
		}
		brute2(pos + 1, oldId, newId, X, Y, mult(val, C[toVec[oldId][pos].second][k]), nX);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	precalc();
	sort(bySum, bySum + m);
	int v = read();
	dp[v][0] = 1;
	for (int i = m - 1; i >= 0; i--) {
		v = bySum[i].second;
		int sum = bySum[i].first;
		for (int x = 0; x + sum <= n; x++) {
			if (dp[v][x] == 0) continue;
			//eprintf("dp[%d][%d] = %d\n", v, x, dp[v][x]);
			brute2(0, v, v, x, n - sum, dp[v][x], 0);
		}
	}
	int ans = 0;
	for (int x = 1; x <= n; x++)
		ans = add(ans, dp[0][x]);
	printf("%d\n", ans);

	return 0;
}