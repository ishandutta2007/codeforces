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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::multiset<std::string> set;
	FOR(i, n){
	std::string s;
		std::cin >> s;
		set.insert(s);
	}
	std::vector<std::string> beg;
	std::vector<std::string> mid;
	while(SZ(set)){
		auto s = *set.begin();
		set.erase(set.begin());
		auto cp = s;
		std::reverse(s.begin(), s.end());
		if(cp == s){
			mid.push_back(cp);
			continue;
		}
		auto xd = set.find(s);
		if(xd != set.end()){
			std::reverse(s.begin(), s.end());
			beg.push_back(s);
			set.erase(xd);
		}
	}
	std::string ans;
	TRAV(i, beg) ans += i;
	std::reverse(beg.begin(), beg.end());
	if(SZ(mid)) ans += mid[0];
	TRAV(i, beg){
		std::reverse(i.begin(), i.end());
		ans += i;
	}
	std::cout << SZ(ans) << "\n";
	std::cout << ans;
	return 0;
}