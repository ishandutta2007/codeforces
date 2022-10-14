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

const int MAXN = 100005;

int n, u[MAXN], cnt[MAXN], CNT[MAXN];

set<int> all_cnt;

int solve() {
	int ans = 1;
	REP(i, n) {
		if (CNT[cnt[u[i]]] == 1) all_cnt.erase(all_cnt.find(cnt[u[i]]));
		--CNT[cnt[u[i]]]; ++cnt[u[i]]; ++CNT[cnt[u[i]]]; all_cnt.insert(cnt[u[i]]);
		if (cnt[u[i]] == i + 1 || (SZ(all_cnt) == 1 && *all_cnt.begin() == 1) || (SZ(all_cnt) == 2 && ((*all_cnt.begin() == 1 && CNT[1] == 1) || (*all_cnt.begin() + 1 == *prev(all_cnt.end()) && CNT[*prev(all_cnt.end())] == 1)))) ans = i + 1;
	}
	return ans;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &u[i]);
	printf("%d", solve());
}

int main() {
	run();
	return 0;
}