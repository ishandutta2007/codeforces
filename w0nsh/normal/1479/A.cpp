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

	int n;
	std::cin >> n;
	int left = 1;
	int right = n;
	while(right - left + 1 > 4){
		int mid = (left+right)/2;
		std::cout << "? " << mid << std::endl;
		int a;
		std::cin >> a;
		std::cout << "? " << mid+1 << std::endl;
		int b;
		std::cin >> b;
		if(a < b) right = mid;
		else left = mid+1;
	}
	VI A(n+3, 1000000000);
	REP(i, left-1, right+2){
		if(i >= 1 && i <= n){
			std::cout << "? " << i << std::endl;
			std::cin >> A[i];
		}
	}
	REP(i, left, right+1){
		if(A[i] < A[i-1] && A[i] < A[i+1]){
			std::cout << "! " << i << std::endl;
			return 0;
		}
	}
	assert(false);


	return 0;
}