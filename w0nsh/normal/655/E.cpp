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
int dp[2000005];
int last[26];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	dp[0] = 1;
	FOR(i, k) last[i] = -1;
	std::string s;
	std::cin >> s;
	FOR(i, SZ(s)) last[s[i]-'a'] = i;
	FOR(i, n){
		PII mn = MP(1000000000, 100);
		FOR(j, k){
			mn = std::min(mn, MP(last[j], j));
		}
		s.push_back((char)('a'+mn.Y));
		last[mn.Y] = SZ(s)+i;
	}
	FOR(i, k) last[i] = -1;
	REP(i, 1, SZ(s)+1){
		int l = last[s[i-1]-'a'];
		int min = (l == -1 ? 0 : dp[l-1]);
		dp[i] = (2*dp[i-1]-min)%MOD;
		if(dp[i] < 0) dp[i] += MOD;
		last[s[i-1]-'a'] = i;
	}
	std::cout << dp[SZ(s)] << "\n";
	return 0;
}