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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A;
	int last = 0;
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(a-last);
		last = a;
	}
	VI ans;
	REP(sz, 1, n+1){
		bool good = true;
		FOR(i, n){
			if(A[i] != A[i%sz]){
				good = false;
				break;
			}
		}
		if(good) ans.push_back(sz);
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}