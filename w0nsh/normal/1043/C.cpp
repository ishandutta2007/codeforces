#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	bool af = str[0] == 'a';
	FOR(i, SZ(str)-1){
		if((str[i+1] == 'a' && af) || (str[i+1] == 'b' && !af)){
			std::cout << 1 << " ";
			af = !af;
		}else{
			std::cout << 0 << " ";
		}
	}
	if(!af){
		std::cout << 1 << " ";
	}else{
		std::cout << 0 << " ";
	}
	return 0;
}