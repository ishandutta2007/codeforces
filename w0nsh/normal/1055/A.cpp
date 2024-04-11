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
	int n, m;
	std::cin >> n >> m;
	VI A, B;
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	FOR(i, n){
		int a;
		std::cin >> a;
		B.push_back(a);
	}
	m--;
	if(A[0] == 0){
		std::cout << "NO\n";
		return 0;
	}
	if(A[m] == 1){
		std::cout << "YES\n";
		return 0;
	}
	if(B[m] == 0){
		std::cout << "NO\n";
		return 0;
	}
	REP(i, m, n) if(A[i] == 1 && B[i] == 1){
		std::cout << "YES\n";
		return 0;
	}
	std::cout << "NO\n";
	return 0;
}