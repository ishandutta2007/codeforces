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

void xd(int ind){
	std::vector<PII> hehe = A;
	int dl = hehe[ind].Y;
	std::swap(hehe[ind], hehe.back());
	hehe.pop_back();
	std::sort(hehe.begin(), hehe.end());
	int r = hehe[1].X-hehe[0].X;
	REP(i, 1, n-1){
		if(hehe[i].X - hehe[i-1].X != r) return;
	}
	std::cout << dl+1 << "\n";
	std::exit(0);
}

void check(int r){
	REP(i, 1, n){
		if(A[i].X-A[i-1].X != r){
			xd(i);
			xd(i-1);
			return;	
		}
	}
	xd(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i].X, A[i].Y = i;
	std::sort(A.begin(), A.end());
	if(n <= 3){
		std::cout << 1 << "\n";
		return 0;
	}
	if(A[0].X == A.back().X){
		std::cout << 1 << "\n";
		return 0;		
	}
	check(A[1].X-A[0].X);
	check(A.back().X-A[SZ(A)-2].X);
	std::cout << -1 << "\n";
	return 0;
}