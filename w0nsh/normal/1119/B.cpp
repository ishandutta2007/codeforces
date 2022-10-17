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
	int n, h;
	std::cin >> n >> h;
	std::multiset<int> set;
	FOR(i, n){
		int a;
		std::cin >> a;
		set.insert(a);
		auto it = set.end();
		ll have = 0;
		do{
			it--;
			have += *it;
			if(it != set.begin()) it--;
			if(have > h) break;
		}while(it != set.begin());
		if(have > h){
			std::cout << i << "\n";
			return 0;
		}
	}
	std::cout << n << "\n";
	return 0;
}