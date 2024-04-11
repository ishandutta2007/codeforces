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
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i], A[i] /= 100;
		std::sort(A.begin(), A.end(), std::greater<int>());
		int x, a, y, b;
		ll k;
		std::cin >> x >> a >> y >> b;
		std::cin >> k;
		if(x < y){
			std::swap(a, b);
			std::swap(x, y);
		}
		int left = 1;
		int right = n+1;
		while(left < right){
			int mid = (left+right)/2;
			ll lcm = 1ll*a*b/std::__gcd(a, b);
			int big = mid/lcm;
			int as = mid/a - big;
			int bs = mid/b - big;
			int pos = 0;
			ll have = 0;
			while(pos < mid && big > 0){
				have += 1ll*(x+y)*A[pos];
				pos++;
				big--;
			}
			while(pos < mid && as > 0){
				have += 1ll*x*A[pos];
				pos++;
				as--;
			}
			while(pos < mid && bs > 0){
				have += 1ll*y*A[pos];
				pos++;
				bs--;
			}
			if(have >= k) right = mid;
			else left = mid+1;
		}
		if(left == n+1) std::cout << -1 << "\n";
		else std::cout << left << "\n";
	}
	return 0;
}