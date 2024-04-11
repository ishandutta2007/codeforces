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

const int MAXN = 1005;

int n, k;
vector<int> primes;

void solve() {
	int cnt = 0;
	for (int i : primes) {
		bool ok = false;
		FOR(j, 0, SZ(primes) - 1) if (primes[j] + primes[j + 1] + 1 == i) ok = true;
		cnt += ok;
	}
	if (cnt >= k) printf("YES");
	else printf("NO");
}

void run() {
	scanf("%d%d", &n, &k);
	FORE(i, 2, n) {
		bool is = true;
		FOR(j, 2, i) if (i % j == 0) is = false;
		if (is) primes.PB(i);
	}
	solve();
}

int main() {
	run();
	return 0;
}