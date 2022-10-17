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
		std::vector<bool> good(n);
		FOR(i, m){
			int a;
			std::cin >> a;
			good[a-1] = true;
		}
		for(int i = n-1; i >= 0; --i){
			REP(j, i, n-1) if(good[j]){
				if(A[j]>A[j+1]) std::swap(A[j], A[j+1]);
			}
		}
		VI xd = A;
		std::sort(xd.begin(), xd.end());
		if(xd == A) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}