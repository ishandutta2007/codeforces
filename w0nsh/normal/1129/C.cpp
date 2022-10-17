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

inline void add(int &a, int b){
	a = (a+b)%MOD;
}

int n, dp[3005][3005], sum[3005][3005], ans[3005];
std::string str;

bool isword(int a, int b){
	if(b - a + 1 < 4) return true;
	if((str[a] == '1' && str[a+1] == '1' && str[a+2] == '0' && str[a+3] == '0')
	|| (str[a] == '1' && str[a+1] == '0' && str[a+2] == '1' && str[a+3] == '0')
	|| (str[a] == '0' && str[a+1] == '1' && str[a+2] == '1' && str[a+3] == '1')
	|| (str[a] == '1' && str[a+1] == '1' && str[a+2] == '1' && str[a+3] == '1'))
		return false;
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	str.resize(n);
	FOR(i, n) std::cin >> str[i];
	std::reverse(str.begin(), str.end());
	FOR(i, n){
		REP(j, i, n){
			if(j - i < 4) dp[i][j] = isword(i, j); 
			REP(k, 1, 5){
				if(j-k < i) continue;
				if(isword(j-k+1, j)) add(dp[i][j], dp[i][j-k]);
			}
		}
		sum[i][i] = dp[i][i];
		REP(j, i+1, n) add(sum[i][j], (dp[i][j]+sum[i][j-1])%MOD);
	}
	std::set<PR<std::string, int> > sufs;
	FOR(i, n) sufs.insert(MP(str.substr(i), i));
	std::set<PR<PII, int> > lcp;
	auto s1 = sufs.begin();
	REP(i, 1, n){
		int ps = 0;
		auto s2 = std::next(s1, 1);
		while(ps < SZ(s1->X) && ps < SZ(s2->X) && s1->X[ps] == s2->X[ps])
			ps++;
		lcp.insert(MP(MP(s1->Y, s2->Y), ps));
		s1 = s2;
	}
	FOR(i, n){
		REP(j, i, n) add(ans[i], sum[j][n-1]);
		TRAV(xd, lcp) add(ans[i], -sum[xd.X.X][xd.X.X+xd.Y-1]);
		if(ans[i] < 0) ans[i] += MOD;
		auto it = sufs.begin();
		while(it->Y != i) it++;
		auto next = std::next(it, 1);
		if(it != sufs.begin()){
			auto prev = std::next(it, -1);
			lcp.erase(lcp.lower_bound(MP(MP(prev->Y, it->Y), -1)));
			if(next != sufs.end()){
				int ps = 0;
				while(ps < SZ(prev->X) && ps < SZ(next->X) && prev->X[ps] == next->X[ps])
					ps++;
				lcp.insert(MP(MP(prev->Y, next->Y), ps));
			}
		}
		if(next != sufs.end()){
			lcp.erase(lcp.lower_bound(MP(MP(it->Y, next->Y), -1)));
		}
		sufs.erase(it);
	}
	std::reverse(ans, ans+n);
	FOR(i, n) std::cout << ans[i] << '\n';
	return 0;
}