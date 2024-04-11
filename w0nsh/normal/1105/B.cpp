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

int n, k;
std::string str;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int best = 0;
	std::cin >> n >> k >> str;
	FOR(i, 26){
		char ch = 'a'+i;
		int curcnt = 0;
		int all = 0;
		FOR(j, n){
			if(str[j] != ch) curcnt = 0;
			else curcnt++;
			if(curcnt == k) all++, curcnt = 0;
		}
		best = std::max(all, best);
	}
	std::cout << best;
	return 0;
}