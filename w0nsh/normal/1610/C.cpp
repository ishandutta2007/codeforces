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
	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y, std::swap(A[i].X, A[i].Y);

	auto check = [&](int m){
		int have = 0;
		FOR(i, n){
			if(A[i].X >= have && A[i].Y >= m - have - 1){
				have++;
			}
		}
		return have >= m;
	};

	int left = 0;
	int right = n+1;
	while(left < right){
		int mid = (left+right)/2;
		if(check(mid)) left = mid+1;
		else right = mid;
	}

	std::cout << left-1 << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}