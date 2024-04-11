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

const int MOD = 1000000007;
int dp[1000005][21][2];

int ile(int n, int x, int y){
	return n/((1<<x)*(y == 1 ? 3 : 1));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int best = 0;
	std::vector<PII> A;
	for(int i = n; i >= 2; --i){
		int t = i;
		int cur = 0;
		while(t % 2 == 0) t /= 2, cur++;
		if(t == 3){
			if(cur+1 == best) A.push_back(MP(cur, 1));
			else if(cur+1 > best){
				A.clear();
				A.push_back(MP(cur, 1));
				best = cur+1;
			}
		}else{
			if(cur == best) A.push_back(MP(cur, 0));
			else if(cur > best){
				A.clear();
				A.push_back(MP(cur, 0));
				best = cur;
			}
		}
	}
	TRAV(i, A) dp[1][i.X][i.Y] = 1;
	REP(i, 2, n+1){
		FOR(x, 21){
			FOR(y, 2){
				dp[i][x][y] = (1ll*dp[i][x][y] + 1ll*dp[i-1][x][y]*(ile(n, x, y)-i+1))%MOD;
				if(x < 20) dp[i][x][y] = (1ll*dp[i][x][y] + 1ll*dp[i-1][x+1][y]*(ile(n, x, y)-ile(n, x+1, y)))%MOD;
				if(y < 1) dp[i][x][y] = (1ll*dp[i][x][y] + 1ll*dp[i-1][x][y+1]*(ile(n, x, y)-ile(n, x, y+1)))%MOD;
			}
		}
	}
	std::cout << dp[n][0][0] << "\n";
	return 0;
}