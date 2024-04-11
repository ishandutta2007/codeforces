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

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	bool zer = false;
	bool on = false;
	bool tw = false;
	bool heh = false;
	FOR(i, n){
		if(A[i] == 0) zer = true;
		if(A[i] == 1) on = true;
		if(A[i] == 2) tw = true;
		if(i < n-1 && A[i] == A[i+1] - 1){
			heh = true;
		}
	}

	if(!on){
		std::cout << "YES\n";
		return;
	}

	if(zer || tw || heh){
		std::cout << "NO\n";
		return;
	}

	std::cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}