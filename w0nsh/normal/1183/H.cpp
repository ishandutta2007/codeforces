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

int last[105][26];
ll took[105][105];
ll dp[105][105];

const ll INF = 10000000000000;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	ll k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	FOR(i, 26) last[0][i] = -1;
	FOR(ch, 26){
		REP(i, 1, n){
			if((int)(s[i-1]-'a') == ch) last[i][ch] = i-1;
			else last[i][ch] = last[i-1][ch];
		}
	}
	// FOR(i, n+1) std::cout << last[i][0] << "\n";
	dp[0][0] = 1;
	REP(i, 1, n+1){
		FOR(j, n+1){
			dp[i][j] = dp[i-1][j] + (j > 0 ? dp[i-1][j-1] : 0ll);
			int lst = last[i-1][s[i-1]-'a'];
			if(lst != -1 && j > 0){
				dp[i][j] -= dp[lst][j-1];
			}
			if(dp[i][j] > INF) dp[i][j] = INF;
		}
	}
	ll price = 0;
	for(int i = n; i >= 0; --i){
		ll have = dp[n][i];
		if(have > k) have = k;
		price += have*(n-i);
		k -= have;
	}
	// FOR(i, n+1){
	// 	FOR(j, n+1){
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	if(k > 0){
		std::cout << -1 << "\n";
	}else{
		std::cout << price << "\n";

	}

	return 0;
}