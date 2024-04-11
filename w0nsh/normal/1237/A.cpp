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
	int what = 0;
	int sum = 0;
	FOR(i, n){
		if(A[i]%2 == 0){
			std::cout << A[i]/2 << "\n";
			sum += A[i]/2;
		}
		else{
			if(A[i] < 0) A[i] = ((A[i]-1)/2);
			else A[i] /= 2;
			std::cout << A[i] + (what) << "\n";
			sum += A[i]+what;
			what = 1-what;
		}
	}
	std::cout << std::flush;
	assert(sum == 0);
	return 0;
}