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
std::vector<PII> A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(a, b));
	}
	int x[2], y[2];
	x[0] = 1e9;
	FOR(i, n) if(A[i].X < x[0]) x[0] = A[i].X;
	x[1] = -1e9;
	FOR(i, n) if(A[i].X > x[1]) x[1] = A[i].X;
	y[0] = 1e9;
	FOR(i, n) if(A[i].Y < y[0]) y[0] = A[i].Y;
	y[1] = -1e9;
	FOR(i, n) if(A[i].Y > y[1]) y[1] = A[i].Y;
	ll best = 0;
	TRAV(i, A) FOR(j, 2) FOR(k, 2) best = std::max(best, 2ll*(std::abs(i.X-x[j])+std::abs(i.Y-y[k])));
	ll all = 0;
	FOR(i, n-1){
		all += std::abs(A[i].X-A[i+1].X) + std::abs(A[i].Y-A[i+1].Y);
	}
	all += std::abs(A[n-1].X-A[0].X) + std::abs(A[n-1].Y-A[0].Y);
	std::cout << best << " ";
	REP(i, 4, n+1){
		std::cout << all << " ";
	}
	
	return 0;
}