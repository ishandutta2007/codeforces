#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
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
	int n;
	std::cin >> n;
	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X, A[i].Y = 2*i;
	std::sort(A.begin(), A.end(), std::greater<PII>());
	std::vector<PII> edges;
	VI path;
	FOR(i, n){
		path.push_back(A[i].Y);
		if(i != n-1) edges.push_back(MP(A[i].Y, A[i+1].Y));
	}
	int mam = n;
	FOR(i, n){
		int cur = A[i].Y+1;
		int ile = A[i].X;
		int parent = path[SZ(path)-1-(mam-ile)];
		edges.push_back(MP(parent, cur));
		if(ile == mam){
			path.push_back(cur);
		}else{
			mam--;
		}
	}
	TRAV(i, edges) std::cout << i.X +1 << " " << i.Y+1 << "\n";
	return 0;
}