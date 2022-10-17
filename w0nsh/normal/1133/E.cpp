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

int n, k, dp[5005][5005];
std::vector<PII> A;
std::map<int, int> map;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	FOR(i, n){
		int a;
		std::cin >> a;
		map[a]++;
	}
	TRAV(i, map) A.push_back(i);
	int mx = 0;
	REP(i, 1, k+1){
		FOR(j, SZ(A)){
			int back = j+1;
			int sm = 0;
			while(back > 0 && A[j].X-A[back-1].X <= 5){
				back--;
				sm += A[back].Y;
				dp[i][j] = std::max(dp[i][j], std::max(std::max((j > 0 ? dp[i][j-1] : 0), dp[i-1][j]),
						(back > 0 ? dp[i-1][back-1] : 0) +sm));
			}
			mx = std::max(mx, dp[i][j]);
		}
	}
	std::cout << mx << "\n";

	return 0;
}