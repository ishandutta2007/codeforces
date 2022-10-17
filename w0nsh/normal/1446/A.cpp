#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
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
		ll w;
		std::cin >> n >> w;
		std::vector<PII> A(n);
		FOR(i, n) std::cin >> A[i].X, A[i].Y = i;
		std::sort(A.begin(), A.end());
		bool good = false;
		FOR(i, n){
			if(2*A[i].X >= w && A[i].X <= w){
				good = true;
				std::cout << 1 << "\n" << A[i].Y+1 << "\n";
				break;
			}
		}
		if(good) continue;

		std::vector<ll> inds;
		ll sum = 0;
		TRAV(pr, A){
			if(2*pr.X < w){
				sum += pr.X;
				inds.push_back(pr.Y+1);
			}
			if(2*sum >= w){
				assert(sum <= w);
				good = true;
				break;
			}
		}
		if(!good) std::cout << -1 << "\n";
		else{
			std::cout << SZ(inds) << "\n";
			TRAV(i, inds) std::cout << i << " ";
			std::cout << "\n";
		}
	}
	return 0;
}