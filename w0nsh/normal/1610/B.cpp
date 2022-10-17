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

bool check(VI A, int co){
	VI nw;
	TRAV(i, A) if(i != co) nw.push_back(i);
	int l = 0;
	int r = SZ(nw)-1;
	while(l < r){
		if(nw[l] != nw[r]) return false;
		l++;
		r--;
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];

		int l = 0;
		int r = n-1;
		bool good = true;
		while(l < r){
			if(A[l] == A[r]){
				l++;
				r--;
			}else{
				if(!check(A, A[l]) && !check(A, A[r])){
					good = false;
				}
				break;
			}
		}

		if(good) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}