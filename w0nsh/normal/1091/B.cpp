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

int n;
std::vector<PII> A;
std::map<PII, int> map;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;
	FOR(i, n){
		int x, y;
		std::cin >> x >> y;
		FOR(j, n){
			map[MP(A[j].X+x, A[j].Y+y)]++;
		}
	}
	TRAV(pr, map) if(pr.Y == n){
		std::cout << pr.X.X << " " << pr.X.Y;
		return 0;
	}
	return 0;
}