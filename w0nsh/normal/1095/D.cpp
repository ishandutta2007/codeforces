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
VI next;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	if(n == 3){
		std::cout << "1 2 3" << "\n";
		return 0;
	}
	next.resize(n);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		A.push_back(MP(a, b));
	}
	FOR(i, n){
		next[i] = A[i].X;
		if(A[A[i].X].X != A[i].Y && A[A[i].X].Y != A[i].Y) next[i] = A[i].Y;
	}
	VI xd;
	xd.push_back(0);
	while(SZ(xd) < n) xd.push_back(next[xd.back()]);
	TRAV(i, xd) std::cout << i+1 << " ";
	return 0;
}