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

const int N = 19;
const int M = (1 << 18) + 7;
int ppc[M];
bool g[N][N];
char s[N];
ll dp[M][N];
ll A[N][M];
ll D[N][M];
vector<int> curPart;
map<vector<int>, ll> ansForPart;
ll B[M];
int n;

void addToPart(int x) {
	int sz = (int)curPart.size();
	curPart.push_back(x);
	for (int i = 0; i < (1 << n); i++)
		D[sz + 1][i] = D[sz][i] * A[x][i];
}
void brutePart(int sum, int mx) {
	int sz = (int)curPart.size();
	if (sum == 0) {
		ll res = 0;
		for (int mask = 0; mask < (1 << n); mask++) {
			if ((n - ppc[mask]) & 1)
				res -= D[sz][mask];
			else
				res += D[sz][mask];
		}
		ansForPart[curPart] = res;
		return;
	}
	while(mx > 0) {
		if (sum >= mx) {
			addToPart(mx);
			brutePart(sum - mx, mx);
			curPart.pop_back();
		}
		mx--;
	}
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int mask = 1; mask < M; mask++)
		ppc[mask] = ppc[mask >> 1] + (mask & 1);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			g[i][j] = s[j] == '1';
	}

	for (int i = 0; i < n; i++)
		dp[1 << i][i] = 1;
	for (int mask = 0; mask < (1 << n); mask++)
		for (int v = 0; v < n; v++) {
			if (dp[mask][v] == 0) continue;
			for (int u = 0; u < n; u++) {
				if ((mask >> u) & 1) continue;
				if (!g[v][u]) continue;
				dp[mask ^ (1 << u)][u] += dp[mask][v];
			}
		}
	A[0][0] = 1;
	for (int mask = 1; mask < (1 << n); mask++)
		for (int v = 0; v < n; v++)
			A[ppc[mask]][mask] += dp[mask][v];
	for (int p = 0; p <= n; p++) {
		for (int k = 0; k < n; k++)
			for (int mask = 0; mask < (1 << n); mask++)
				if ((mask >> k) & 1)
					A[p][mask] += A[p][mask ^ (1 << k)];
	}

	for (int i = 0; i < (1 << n); i++)
		D[0][i] = 1;
	curPart.clear();
	brutePart(n, n);

	for (int mask = 0; mask < (1 << (n - 1)); mask++) {
		vector<int> pp;
		int cur = 1;
		for (int i = 0; i < n - 1; i++) {
			if ((mask >> i) & 1) {
				cur++;
			} else {
				pp.push_back(cur);
				cur = 1;
			}
		}
		pp.push_back(cur);
		sort(pp.begin(), pp.end());
		reverse(pp.begin(), pp.end());
		B[mask] = ansForPart[pp];
	}

	for (int k = 0; k < n - 1; k++)
		for (int mask = 0; mask < (1 << (n - 1)); mask++)
			if (((mask >> k) & 1) == 0)
				B[mask] -= B[mask ^ (1 << k)];
	for (int i = 0; i < (1 << (n - 1)); i++)
		printf("%lld ", B[i]);
	printf("\n");

	return 0;
}