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
		int n, m;
		std::cin >> n >> m;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		int pos = 1;
		while(pos < n){
			int moge = std::min(m-A[0], A[pos]);
			if(moge > 0){
				A[0] += moge;
				A[pos] -= moge;
			}
			pos++;
		}
		std::cout << A[0] << "\n";
	}
	return 0;
}