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
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	if(A[0] != A[n-1]){
		std::cout << n-1;
		return 0;
	}
	int left = 0;
	int right = n-1;
	while(left < n && A[left] == A[n-1]){
		left++;
	}
	while(right >= 0 && A[right] == A[0]){
		right--;
	}
	std::cout << std::max(n-1-left, right);
	return 0;
}