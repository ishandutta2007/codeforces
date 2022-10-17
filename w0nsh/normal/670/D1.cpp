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
	int n, k;
	std::cin >> n >> k;
	VI A(n), B(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) std::cin >> B[i];
	ll left = 0;
	ll right = 2000000005ll;
	while(left < right){
		ll mid = (left+right)/2;
		ll need = 0;
		FOR(i, n){
			need += std::max(0ll, mid*A[i]-B[i]);
			if(need > k) need = k+1;
		}
		if(need > k) right = mid;
		else left = mid+1;
	}
	std::cout << left-1 << "\n";
	return 0;
}