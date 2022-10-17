#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void solve(){
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::set<char> set;
	TRAV(i, s) set.insert(i);
	if(SZ(set) == 1){
		std::cout << (n+2)/3 << "\n";
		return;
	}
	int start = -1;
	FOR(i, n-1){
		if(s[i] != s[i+1]){
			start = i+1;
		}
	}
	assert(start != -1);
	std::string xd = s.substr(start) + s.substr(0, start);
	int have = 1;
	int ans = 0;
	REP(i, 1, n){
		if(xd[i-1] == xd[i]) have++;
		else{
			ans += have/3;
			have = 1;
		}
	}
	ans += have/3;
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}