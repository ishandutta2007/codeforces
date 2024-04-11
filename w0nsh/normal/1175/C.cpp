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
VI A;

// bool check(int w){
// 	FOR(i, n){
// 		if()
// 	}
// }

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n >> k;
		A.resize(n);
		FOR(i, n) std::cin >> A[i];
		PII best = MP(1000000001, -1);
		FOR(i, n-k){
			best = std::min(MP((A[i+k]-A[i]+1)/2, (A[i+k]+A[i])/2), best);
		}
		std::cout << best.Y << "\n";
		// int left = 0;
		// int right = 1000000001;
		// while(left < right){
		// 	int mid = (left+right)/2;
		// 	if(check(mid)) right = mid;
		// 	else left = mid+1;
		// }
		// std::cout << left << "\n";
	}
	return 0;
}