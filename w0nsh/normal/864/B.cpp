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

std::set<char> was;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::string str;
	std::cin >> n >> str;
	int best = 0;
	FOR(i, n){
		if((int)str[i] >= (int)'a') was.insert(str[i]);
		else{
			best = std::max(best, SZ(was));
			was.clear();
		}
	}
	best = std::max(best, SZ(was));
	std::cout << best << "\n";
	return 0;
}