#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int sq(int n){
	int left = 1;
	int right = 1000000666;
	while(left <= right){
		int mid = (left+right)/2;
		if(1ll*mid*mid == n) return mid;
		if(1ll*mid*mid > n) right = mid-1;
		else left = mid+1;
	}
	return 0;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		if(n % 2 == 1){
			std::cout << "NO\n";
		}else{
			n /= 2;
			if (sq(n) || (n % 2 == 0 && sq(n / 2))){
				std::cout << "YES\n";
			}else{
				std::cout << "NO\n";
			}

		}
	}

	return 0;
}