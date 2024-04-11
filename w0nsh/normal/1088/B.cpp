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
	int n, k;
	std::set<ll> A;
	std::cin >> n >> k;
	FOR(i, n){
		int a;
		std::cin >> a;
		A.insert(a);	
	}
	ll min = 0;
	FOR(i, k){
		if(!A.empty()) (std::cout << *A.begin()-min << "\n"), min += *A.begin() - min, A.erase(A.begin());
		else std::cout << 0 << "\n";
	}
	return 0;
}