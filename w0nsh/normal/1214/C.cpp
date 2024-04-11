#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
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
	std::string str;
	std::cin >> n >> str;
	int have = 0;
	int need = 0;
	FOR(i, n){
		if(str[i] == '(') have++;
		else have--;
		if(have == -1 && need != 0){
			std::cout << "No\n";
			return 0;
		}
		if(have == -1) need = 1, have++;
	}
	if(have == need) std::cout << "Yes\n";
	else std::cout << "No\n";
	return 0;
}