#include <bits/stdc++.h>
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

int n;
VI A;
int dp[5005][5005][2];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int last = -1;
	FOR(i, n){
		int a;
		std::cin >> a;
		if(a == last) continue;
		last = a;
		A.push_back(a);
	}
	n = SZ(A);
	REP(sz, 2, n+1){
		FOR(i, n-sz+1){
			if(A[i] == A[i+sz-1])
				dp[i][i+sz-1][0] = dp[i][i+sz-1][1] = std::min(dp[i][i+sz-2][0], dp[i+1][i+sz-1][1]);
			else{
				dp[i][i+sz-1][0] = std::min(dp[i+1][i+sz-1][0], dp[i+1][i+sz-1][1]) + 1;
				dp[i][i+sz-1][1] = std::min(dp[i][i+sz-2][0], dp[i][i+sz-2][1]) + 1;
			}
		}
	}
	std::cout << std::min(dp[0][n-1][0], dp[0][n-1][1]) << "\n";
	return 0;
}