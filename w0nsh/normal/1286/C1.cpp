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
	if(n == 1){
		std::cout << "? 1 1" << std::endl;
		std::string x;
		std::cin >> x;
		std::cout << "! " << x << std::endl;
		return 0;
	}
	std::multiset<std::string> set;
	std::cout << "? 1 " << n << std::endl;
	FOR(i, n){
		REP(j, i, n){
			std::string x;
			std::cin >> x;
			std::sort(x.begin(), x.end());
			set.insert(x);
		}
	}
	std::cout << "? 2 " << n << std::endl;
	FOR(i, n-1){
		REP(j, i, n-1){
			std::string x;
			std::cin >> x;
			std::sort(x.begin(), x.end());
			set.erase(set.find(x));
		}
	}
	std::vector<std::multiset<char> > xd;
	TRAV(i, set){
		xd.emplace_back();
		TRAV(j, i) xd.back().insert(j);
	}
	std::sort(xd.begin(), xd.end(), [](std::multiset<char> &a, std::multiset<char> &b){
		return SZ(a) < SZ(b);
	} );
	std::multiset<char> dl;
	std::cout << "! ";
	TRAV(i, xd){
		TRAV(j, dl) i.erase(i.find(j));
		dl.insert(*i.begin());
		std::cout << *i.begin();
	}
	std::cout << std::endl;
	return 0;
}