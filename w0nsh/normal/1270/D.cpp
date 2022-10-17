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
	int n, k;
	std::cin >> n >> k;
	if(k == 1){
		std::cout << "! 1" << std::endl;
		return 0;
	}
	std::vector<PII> A;
	std::set<int> set;
	FOR(i, n) set.insert(i);
	while(SZ(set) >= k){
		int cnt = 0;
		std::cout << "? ";
		TRAV(i, set){
			std::cout << i+1 << " ";
			cnt++;
			if(cnt == k) break;
		}
		std::cout << std::endl;
		int p, a;
		std::cin >> p >> a;
		A.push_back(MP(p-1, a));
		set.erase(p-1);
	}
	int ile = 0;
	if(A[0].Y > A[1].Y) std::swap(A[0], A[1]);
	TRAV(c, set){
		std::cout << "? ";
		std::cout << A[0].X+1 << " " << A[1].X+1 << " ";
		TRAV(i, set) if(i != c){
			std::cout << i+1 << " ";
		}
		std::cout << std::endl;
		int p, a;
		std::cin >> p >> a;
		p--;
		if(p == A[1].X) ile++;
	}
	std::cout << "! " << ile+1 << std::endl;
	return 0;
}