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
#include <bitset>
#include <ctime>
#include <random>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int n, A[705];
bool dp[705][705][2], done[705][705][2], can[705][705];

bool rec(int i, int j, int side){
	if(i > j) return true;
	if(done[i][j][side]) return dp[i][j][side];
	int root = (side ? j+1 : i-1);
	REP(k, i, j+1){
		if(can[root][k] && (rec(i, k-1, 1) && rec(k+1, j, 0))){
			dp[i][j][side] = true;
			break;
		}
	}
	done[i][j][side] = true;
	return dp[i][j][side];
}

int main(){
	std::scanf("%d", &n);
	FOR(i, n) std::scanf("%d", &A[i]);
	FOR(i, n) FOR(j, n) can[i][j] = std::__gcd(A[i], A[j]) > 1;
	REP(i, 0, n-1) dp[i][i][1] = can[i][i+1];
	REP(i, 1, n) dp[i][i][0] = can[i][i-1];
	FOR(i, n) done[i][i][0] = done[i][i][1] = true;
	bool good = false;
	FOR(i, n){
		if(rec(0, i-1, 1) && rec(i+1, n-1, 0)){
			good = true;
			break;
		}
	}
	if(good) std::cout << "Yes\n";
	else std::cout << "No\n";
	return 0;
}