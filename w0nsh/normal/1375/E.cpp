#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
/*
const int INF = 1000000666;
struct Tree{
	int BOTTOM;
	std::vector<PII> t;

	void build(VI A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t.resize(BOTTOM*2, MP(-INF, -1));
		FOR(i, SZ(A))
	}
};
*/
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];


	std::vector<PII> ans;
	FOR(i, n){
		std::vector<PII> heh;
		REP(j, i+1, n){
			if(A[i] > A[j]){
				heh.push_back(MP(A[j], j));
			}
		}
		std::sort(heh.begin(), heh.end());
		std::reverse(heh.begin(), heh.end());
		TRAV(k, heh){
			ans.push_back(MP(i, k.Y));
		}

	}

	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i.X+1 << " " << i.Y+1 << "\n";

	return 0;
}