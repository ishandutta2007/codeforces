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
	std::string str;
	std::cin >> str;
	bool was = false;
	FOR(i, SZ(str)/2){
		if(str[i] != str[SZ(str)-1-i]){
			if(was){
				std::cout << "NO\n";
				return 0;
			}
			was = true;
		}
	}
	if(was || SZ(str)%2 == 1) std::cout << "YES\n";
	else std::cout << "NO\n";
	return 0;
}