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
	int q;
	std::cin >> q;
	while(q--){
		std::multiset<char> have;
		std::string s, t, p;
		std::cin >> s >> t >> p;
		TRAV(ch, p) have.insert(ch);
		int pos = 0;
		bool good = true;
		FOR(i, SZ(t)){
			if(pos == SZ(s) || t[i] != s[pos]){
				if(have.find(t[i]) == have.end()){
					good = false;
					break;
				}
				have.erase(have.find(t[i]));
			}else{
				pos++;
			}
		}
		if(pos != SZ(s) || !good) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
	return 0;
}