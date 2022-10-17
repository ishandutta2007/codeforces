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
	std::string s;
	std::cin >> s;
	std::set<char> was;
	FOR(i, SZ(s)){
		if(was.empty() || *was.begin() >= s[i]) std::cout << "Mike\n";
		else std::cout << "Ann\n";
		was.insert(s[i]);
	}
	return 0;
}