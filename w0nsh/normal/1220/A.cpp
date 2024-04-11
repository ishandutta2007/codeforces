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
	int z = 0, o = 0;
	FOR(i, n){
		char ch;
		std::cin >> ch;
		if(ch == 'z') z++;
		else if(ch == 'n') o++;
	}
	FOR(i, o) std::cout << 1 << " ";
	FOR(i, z) std::cout << 0 << " ";
	return 0;
}