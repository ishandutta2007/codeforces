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

void ans(int what){
	if(what == 0) std::cout << "cslnb";
	else std::cout << "sjfnb";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	int bad = -1;
	FOR(i, n-1){
		if(A[i] == A[i+1]){
			if(bad != -1) ans(0);
			bad = i;
		}
	}
	if(bad != -1 && A[bad] == 0) ans(0);
	if(bad > 0 && A[bad-1] == A[bad]-1) ans(0);
	ll moves = 0;
	FOR(i, n){
		moves += A[i]-i;
	}
	if(moves % 2 == 1) ans(1);
	else ans(0);

	return 0;
}