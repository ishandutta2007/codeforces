#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void solve(){
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	if(SZ(s) == 1 || s[0] == s[1]){
		std::cout << s[0] << s[0] << "\n";
		return;
	}


	std::string xd;
	xd.push_back(s[0]);
	REP(i, 1, SZ(s)){
		if(s[i] <= xd.back()) xd.push_back(s[i]);
		else break;
	}

	std::cout << xd;
	std::reverse(xd.begin(), xd.end());
	std::cout << xd << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}