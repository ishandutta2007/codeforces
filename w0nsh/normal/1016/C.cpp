#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#define int long long
#define FOR(i, n) for(int i = 1; i <= (n); ++i)
#define FORD(i, n) for(int i = (n); i >= 1; --i)
#define REP(i, a, b) for(int i = (a); i <= (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int n, A[3][300005], _sum[3][300005], dp[3][300005];

int sum(int a, int b){
	int ret = 0;
	if(a != -1) ret += _sum[1][a];
	if(b != -1) ret += _sum[2][b];
	return ret;
}

void calc(){
	FOR(i, 2) FORD(j, n) _sum[i][j] = _sum[i][j+1] + A[i][j];
	FORD(j, n) dp[1][j] = dp[1][j+1] + sum(j+1, j) + 2ll*(n-j)*A[2][j];
	FORD(j, n) dp[2][j] = dp[2][j+1] + sum(j, j+1) + 2ll*(n-j)*A[1][j];
}

int go(int y, int x, int steps){
	return dp[y][x] + steps*sum(x + (y == 1 ? 1 : 0), x + (y == 2 ? 1 : 0));
}

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, 2) FOR(j, n) std::cin >> A[i][j];
	calc();
	int best = 0;
	int steps = 0;
	int have = 0;
	int pos = 1;
	int which = 1;
	while(steps < n*2-1){
		best = std::max(best, have + go(which, pos, steps));
//		std::cout << have + go(which, pos, steps) << " <\n";
		which++;steps++;
		if(which == 3) which = 1;
		have += steps*A[which][pos];
		pos++;
		if(steps < n*2-1){
			steps++;
			have += steps*A[which][pos];
		}
	}
//	std::cout << have << "\n";
//	std::cout << best << "\n";
	std::cout << std::max(have, best) << "\n";
	return 0;
}