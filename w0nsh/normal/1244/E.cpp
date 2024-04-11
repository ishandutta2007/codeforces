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
	int n;
	ll k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	int lg = 0;
	int rg = 1000000001;
	while(lg < rg){
		int gap = (lg+rg)/2;
		int left = 0;
		int right = 1000000001;
		while(left < right){
			int mid = (left+right)/2;
			int l = mid;
			int r = mid+gap;
			int lbad = 0;
			int rbad = 0;
			FOR(i, n){
				if(A[i] <= l) rbad++;
				if(A[i] >= r) lbad++;
			}
			if(lbad == rbad){
				left = mid;
				break;
			}
			if(lbad > rbad) left = mid+1;
			else right = mid;
		}
		ll mn = 1000000000ll*1000000000ll;
		REP(place, std::max(0, left-2), left+3){
			int l = place;
			int r = place+gap;
			ll cur = 0;
			FOR(i, n){
				if(A[i] < l) cur += l-A[i];
				if(A[i] > r) cur += A[i]-r;
			}
			mn = std::min(cur, mn);
		}
		if(mn > k) lg = gap+1;
		else rg = gap;
	}
	std::cout << lg;
	return 0;
}