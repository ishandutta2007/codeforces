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
	ll n, k;
	std::cin >> n >> k;
	ll left = 0;
	ll right = n;
	while(left <= right){
		ll mid = (left+right)/2;
		ll xd = mid*(mid+1)/2ll - (n-mid);
		if(xd == k){
			std::cout << n-mid << "\n";
			return 0;
		}else if(xd < k) left = mid+1;
		else right = mid - 1;
	}
	return 0;
}