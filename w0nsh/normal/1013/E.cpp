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

#define int long long

const int INF = 2000000666;

int n;
int dp[5005][5005];
int far[5005], last[5005][5005];
VI A;

// zbudowac na i
int roz(int i, int j){
	if(j < 1 || j > n) return 0;
	return std::max(0, A[j]-A[i] + 1);
}

void calc_dp(){
	REP(i, 1, n+1) REP(j, 1, (n+1)/2+1) dp[i][j] = INF;
	REP(i, 1, (n+1)/2+1) far[i] = INF;
	REP(i, 0, n+1) REP(j, 1, (n+1)/2+1) last[i][j] = INF;
	dp[1][1] = roz(1, 2);
	last[1][1] = roz(1, 2);
	REP(i, 2, n+1){
		REP(j, 1, (n+1)/2+1){
			int here_min = INF;
			dp[i][j] = dp[i-1][j];
			if(i > 2 && j > 1){
				dp[i][j] = std::min(dp[i][j], last[i-2][j]);
				if(last[i-2][j-1] != INF){
					int more = std::max(0, std::min(A[i-1], A[i-2]-1) - A[i] + 1);
					//if(last[i-2][j-1] + more + roz(i, i+1) < dp[i][j]) std::cout << "adding more=" << more << " i j = " << i << " " << j << "\n";
					dp[i][j] = std::min(dp[i][j], last[i-2][j-1] + more + roz(i, i+1));
					here_min = std::min(last[i-2][j-1] + more + roz(i, i+1), here_min);
				}
			}
			dp[i][j] = std::min(dp[i][j], far[j]);
			if(far[j-1] != INF){
				dp[i][j] = std::min(dp[i][j], far[j-1]+roz(i, i+1)+roz(i, i-1));
				here_min = std::min(far[j-1]+roz(i, i+1)+roz(i, i-1), here_min);
			}
			last[i][j] = here_min;
		}
		if(i >= 3){
			REP(j, 1, (n+1)/2+1){
				far[j] = std::min(dp[i-2][j], far[j]);
			}
		}	
	}
}

void answer(){
	/*REP(i,1,n+1){
		FOR(j, (n+1)/2+1){
			std::cout << dp[i][j] << " ";
		}
		std::cout << "\n";
	}*/
	REP(j, 1, (n+1)/2+1){
		std::cout << dp[n][j] << " ";
	}
}

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n+1);
	FOR(i, n) std::cin >> A[i+1];
	calc_dp();
	answer();
	return 0;
}