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
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	int k = 0;
	FOR(i, n) k = std::max(k, A[i]);
	while(true){
		int va = 0, vb = 0;
		FOR(i, n){
			va += k-A[i];
			vb += A[i];
		}
		if(va > vb){
			std::cout << k << "\n";
			return 0;
		}
		k++;
	}
	return 0;
}