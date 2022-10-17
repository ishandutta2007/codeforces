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

const int INF = 1000000666;
int n;
VI A;

int check(){
	int ret = 0;
	int r = A[1]-A[0];
	int last = A[1];
	REP(i, 2, n){
		int bs = std::abs(A[i]-last-r);
		if(bs > 1) return INF;
		if(bs == 1) ret++;
		last += r;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	if(n == 1){
		std::cout << 0 << "\n";
		return 0;
	}
	int best = INF;
	best = std::min(best, check());
	A[1]--;
	best = std::min(best, check()+1);
	A[1] += 2;
	best = std::min(best, check()+1);
	A[0]--; A[1]--;
	best = std::min(best, check()+1);
	A[1]--;
	best = std::min(best, check()+2);
	A[1] += 2;
	best = std::min(best, check()+2);
	A[0] += 2; A[1]--;
	best = std::min(best, check()+1);
	A[1]--;
	best = std::min(best, check()+2);
	A[1] += 2;
	best = std::min(best, check()+2);
	if(best == INF) std::cout << -1 << "\n";
	else std::cout << best << "\n";
	return 0;
}