#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		std::vector<PR<std::string, int> > A;
		FOR(i, n-1){
			std::string xd = s.substr(0, i);
			if(i%2 != n%2) std::reverse(xd.begin(), xd.end());
			A.push_back(MP(s.substr(i, n-i)+xd, i+1));
		}
		std::reverse(s.begin(), s.end());
		A.push_back(MP(s, n));
		std::sort(A.begin(), A.end());
		std::cout << A[0].X << "\n" << A[0].Y << "\n";
	}
	return 0;
}