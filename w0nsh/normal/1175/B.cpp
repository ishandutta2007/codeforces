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

const ll BAD = (1ll<<32);

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int l;
	std::cin >> l;
	std::vector<ll> fors;
	fors.push_back(1ll);
	ll x = 0;
	FOR(i, l){
		std::string com;
		std::cin >> com;
		if(com == "add"){
			if(fors.back() + x >= BAD){
				std::cout << "OVERFLOW!!!\n";
				return 0;
			}
			x += fors.back();
		}else if(com == "end") fors.pop_back();
		else{
			ll ile;
			std::cin >> ile;
			fors.push_back(std::min(1000000000000ll, fors.back()*ile));
		}
	}
	std::cout << x << "\n";
	return 0;
}