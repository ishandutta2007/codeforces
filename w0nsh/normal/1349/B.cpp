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
		int n, k;
		std::cin >> n >> k;
		VI A(n);
		bool was = false;
		FOR(i, n){
			std::cin >> A[i];
			if(A[i] == k) was = true;
			if(A[i] >= k) A[i] = 1;
			else A[i] = -1;
		}
		if(!was){
			std::cout << "no\n";
			continue;
		}
		if(n == 1){
			std::cout << "yes\n";
			continue;
		}
		VI pref(n+1);
		REP(i, 1, n+1) pref[i] = pref[i-1]+A[i-1];
		std::multiset<int> mam;
		bool good = false;
		REP(i, 1, n+1){
			if(mam.lower_bound(pref[i]) != mam.begin()){
				good = true;
				break;
			}
			mam.insert(pref[i-1]);
		}
		if(good) std::cout << "yes\n";
		else std::cout << "no\n";
	}

	return 0;
}