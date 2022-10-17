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

bool perfect(int x){
	if(x == 0) return true;
	if(x%2 == 0) return false;
	bool was = false;
	REP(i, 1, 22){
		if((x & (1<<i)) == 0) was = true;
		else if(was) return false; 
	}
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int x;
	std::cin >> x;
	VI ops;
	int opcnt = 0;
	while(!perfect(x)){
		// std::cout << std::bitset<10>(x) << std::endl;
		int last = -1;
		bool zr = true;
		FOR(i, 22){
			if(x & (1<<i)){
				if(zr) last = i;
				zr = false;
			}else zr = true;
		}
		// std::cout << last << std::endl;
		ops.push_back(last);
		x = x^((1<<last)-1);
		// std::cout << std::bitset<10>(x) << std::endl;

		opcnt++;
		if(perfect(x)) break;

		x++;
		opcnt++;
		// std::cout << std::bitset<10>(x) << std::endl;
		// int xd;
		// std::cin >> xd;
	}
	std::cout << opcnt << "\n";
	TRAV(i, ops) std::cout << i << " ";
	return 0;
}