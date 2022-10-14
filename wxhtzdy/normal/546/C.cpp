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

const int MAXN = 10;

int n, k1, k2;
deque<int> a, b;

void solve() {
	int turn = 0;
	while (turn < 10000 && max(SZ(a), SZ(b)) < n) {
		int x = a[0], y = b[0]; a.pop_front(); b.pop_front();
		if (x > y) a.PB(y), a.PB(x);
		else b.PB(x), b.PB(y);
		++turn;
	}
	if (turn == 10000) printf("-1");
	else {
		printf("%d ", turn);
		if (SZ(a) == n) printf("1");
		else printf("2");
	}
}

void run() {
	scanf("%d", &n);
	scanf("%d", &k1);
	int x; REP(i, k1) scanf("%d", &x), a.PB(x);
	scanf("%d", &k2);
	int y; REP(i, k2) scanf("%d", &y), b.PB(y);
	solve();
}

int main() {
	run();
	return 0;
}