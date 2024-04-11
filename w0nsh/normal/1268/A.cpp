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
	int n, k;
	std::string s;
	std::cin >> n >> k >> s;
	std::string my;
	FOR(i, k) my.push_back(s[i]);
	while(SZ(my) != n){
		my.push_back(my[SZ(my)-k]);
	}
	if(my >= s){
		std::cout << SZ(my) << "\n";
		std::cout << my << "\n";
	}else{
		my = "";
		FOR(i, k) my.push_back(s[i]);
		int pos = SZ(my)-1;
		while(true){
			if(my[pos] != '9'){
				my[pos]++;
				break;
			}else{
				my[pos] = '0';
			}
			pos--;
		}
		while(SZ(my) != n){
			my.push_back(my[SZ(my)-k]);
		}
		assert(my >= s);
		std::cout << SZ(my) << "\n";
		std::cout << my << "\n";
	}
	return 0;
}