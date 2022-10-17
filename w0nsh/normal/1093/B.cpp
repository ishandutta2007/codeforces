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


int t;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >>t;
	while(t--){
		std::string a;
		std::cin >> a;
		std::sort(a.begin(), a.end());
		bool good = false;
		FOR(i, SZ(a)/2) if(a[i] != a[SZ(a)-1-i]) good = true;
		if(good) std::cout << a << "\n";
		else std::cout << -1 << "\n";
	}
	return 0;
}