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
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		FOR(i, n){
			int a;
			std::cin >> a;
			A[i] = a-A[i];
		}
		int start = 0;
		std::set<int> wart;
		if(A[0] != 0) start = 1;
		FOR(i, n-1){
			if(A[i] == 0 && A[i+1] != 0) start++;
			wart.insert(A[i]);
		}
		wart.insert(A[n-1]);
		wart.erase(0);
		if(start > 1 || SZ(wart) > 1 || (SZ(wart) > 0 && *wart.begin() < 0)) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
	return 0;
}