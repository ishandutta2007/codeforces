#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <list>
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 18;

int n;
double a[MAXN][MAXN];

void solve() {
	vector<double> dp(1 << n); dp[(1 << n) - 1] = 1;
	for (int i = (1 << n) - 1; i >= 0; i--) {
		int fish = 0;
		REP(j, n) if (i & (1 << j)) ++fish;
		REP(j, n) if (i & (1 << j)) FOR(k, j + 1, n) if (i & (1 << k)) {
			dp[i ^ (1 << j)] += dp[i] * a[k][j] / (fish * (fish - 1) / 2);
			dp[i ^ (1 << k)] += dp[i] * a[j][k] / (fish * (fish - 1) / 2);
		}
	}
	REP(i, n) printf("%.6lf ", dp[1 << i]);
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%lf", &a[i][j]);
	solve();
}

int main() {
	run();
	return 0;
}