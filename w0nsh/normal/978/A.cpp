#include <bits/stdc++.h>
#define ll long long
#define FOR(i, n) for(int i =0; i  < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define PR std::pair
#define PII std::pair<int, int>
#define SZ(i) ((int)((i).size()))
#define VI std::vector<int>
#define MP std::make_pair
#define X first
#define Y second

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::set<int> was;
	VI ans;
	for(int i = n-1; i >= 0; --i){
		if(was.count(A[i]) == 0) ans.push_back(A[i]);
		was.insert(A[i]);
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}