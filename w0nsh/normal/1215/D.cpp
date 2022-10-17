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

void ans(int who){
	if(who == 0) std::cout << "Monocarp\n";
	else std::cout << "Bicarp\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int sum = 0;
	int plus = 0, minus = 0;
	FOR(i, n/2){
		char c;
		std::cin >> c;
		if(c == '?') plus++;
		else sum += c-'0';
	}
	FOR(i, n/2){
		char c;
		std::cin >> c;
		if(c == '?') minus++;
		else sum -= c-'0';
	}
	if(sum == (minus-plus)/2*9) ans(1);
	ans(0);
	return 0;
}