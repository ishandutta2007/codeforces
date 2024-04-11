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
	A.push_back(0);
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	A.push_back(1001);
	int ans = 0;
	int best = 0;
	REP(i, 1, n+1){
		if(A[i] == A[i-1]+1 && A[i] == A[i+1]-1) ans++;
		else{
			best = std::max(best, ans);
			ans = 0;
		}
	}
	std::cout << std::max(best, ans) << "\n";
	return 0;
}