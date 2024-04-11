#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

bool solve(){
	int n, c;
	std::cin >> n >> c;
	VI A(c+1);
	FOR(i, n){
		int a;
		std::cin >> a;
		A[a] = 1;
	}

	VI B(c+1);
	REP(i, 1, SZ(B)){
		B[i] = B[i-1] + A[i];
	}

	REP(s, 2, SZ(B)){
		if(!A[s]) continue;

		int kt = 1;
		int lef = s;
		int rig = 2*s-1;
		while(kt < SZ(B) && lef < SZ(B)){
			if(!A[kt]){
				int upto = std::min(SZ(B)-1, rig);
				if(B[upto] - B[lef-1]){
					return false;
				}
			}
			kt++;
			lef += s;
			rig += s;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) std::cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}