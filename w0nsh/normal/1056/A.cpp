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

int n;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::set<int> xd;
	int r;
	std::cin >> r;
	FOR(i, r){
		int a;
		std::cin >> a;
		xd.insert(a);
	}
	std::set<int> st;
	FOR(i, n-1){
		std::cin >> r;
		FOR(j, r){
			int a;
			std::cin >> a;
			if(xd.count(a)) st.insert(a);
		}
		xd = st;
		st.clear();
	}
	TRAV(i, xd) std::cout << i << " ";
	return 0;
}