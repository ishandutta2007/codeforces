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
	int n;
	std::cin >> n;
	std::vector<std::string> A;
	bool good = false;
	FOR(i, n){
		std::string s;
		std::cin >> s;
		if(good){
			A.push_back(s);
			continue;
		}
		if(s[0] == s[1] && s[0] == 'O') s[0] = s[1] = '+', good = true;
		else if(s[3] == s[4] && s[4] == 'O') s[3] = s[4] = '+', good = true;
		A.push_back(s);
	}
	if(!good) std::cout << "NO\n";
	else{
		std::cout << "YES\n";
		TRAV(i, A) std::cout << i << "\n";
	}
	return 0;
}