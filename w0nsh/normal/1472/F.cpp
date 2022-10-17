#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
 
void solve(){
	int n, m;
	std::cin >> n >> m;

	std::vector<PII> heh;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		heh.push_back(MP(b, a));
	}
	std::sort(heh.begin(), heh.end());
	int odj = 0;
	std::vector<PII> real;
	int lst = 0;
	TRAV(pr, heh){
		if(pr.X - lst > 4){
			int xd = pr.X - lst - 4;
			if(xd & 1) xd--;
			odj += xd;
		}
		lst = pr.X;
		real.push_back(MP(pr.X-odj, pr.Y));
	}

	if(n - lst > 4){
		int xd = n - lst - 4;
		if(xd & 1) xd--;
		odj += xd;
	}


assert(n - odj < 10000000);
	
	std::vector<std::array<bool, 4>> over(n - odj, std::array<bool, 4>{true, true, true, true});
	std::vector<std::array<bool, 2>> have(n - odj, std::array<bool, 2>{false, false});
	assert(n - odj > real.back().X);
	TRAV(pr, real){
		if(pr.Y == 0) over[pr.X][0] = over[pr.X][1] = false;
		else over[pr.X][0] = over[pr.X][2] = false;
		assert(pr.Y <= 1);
		have[pr.X][pr.Y] = true;
	}
	decltype(over) dp(n - odj);
	FOR(i, n-odj){
		std::array<bool, 4> last = (i == 0 ? std::array<bool, 4>{false, false, false, true} : dp[i-1]);
		dp[i][0] = last[0] || last[3];
		dp[i][1] = last[2];
		dp[i][2] = last[1];
		dp[i][3] = last[0] || last[3];
		if(have[i][0] && have[i][1]){
			dp[i][3] = dp[i][0];
		}else if(have[i][0]){
			dp[i][3] = dp[i][1];
			dp[i][2] = dp[i][0];
		}else if(have[i][1]){
			dp[i][3] = dp[i][2];
			dp[i][1] = dp[i][0];
		}
		FOR(j, 4) dp[i][j] &= over[i][j];
	}

	if(dp[n-odj-1][3]){
		std::cout << "YES\n";
	}else{
		std::cout << "NO\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}