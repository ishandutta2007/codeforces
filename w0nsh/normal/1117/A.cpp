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
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	int mx = *std::max_element(A.begin(), A.end());
	int best = 1;
	int last = 0;
	FOR(i, n){
		if(A[i] == A[last]){
			if(A[i] == mx) best = std::max(best, i-last+1);
		}
		else last = i;
	}
	std::cout << best;
	return 0;
}