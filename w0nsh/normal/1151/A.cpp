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

int dist(char a, char b){
	if(a > b) std::swap(a, b);
	return std::min((int)b-(int)a, (int)a-(int)b+26);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::string str;
	std::cin >> n >> str;
	int best = 1000000;
	FOR(i, n-3){
		best = std::min(best, dist(str[i], 'A')+dist(str[i+1], 'C') + dist(str[i+2], 'T') + dist(str[i+3], 'G'));
	}
	std::cout << best;
	return 0;
}