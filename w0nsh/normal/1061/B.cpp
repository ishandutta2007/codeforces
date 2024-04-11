#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, m;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	if(n == 1){
		std::cout << 0 << "\n";
		return 0;
	}
	FOR(i, n){
		int a;
		std::cin >> a;
		if(a > 0) A.push_back(a);
	}
	std::sort(A.begin(), A.end(), std::greater<int>());
	ll ans = 0;
	int done = A[0];
	FOR(i, SZ(A)-1){
		if(done == 0){
			ans += A[i]-1;
			continue;
		}
		if(done <= A[i+1]){
			ans += A[i]-1;
			done--;
		}else{
			ans += A[i]-(done-A[i+1]);
			done = A[i+1];
		}
	}
	ans += std::min(A.back()-1, A.back()-done);
	std::cout << ans << "\n";
	return 0;
}