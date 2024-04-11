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

	auto can = [&](int m){
		auto B = A;
		int cnt = m;
		FOR(i, n){
			if(cnt == 0) break;
			if(B[i] == 1){
				cnt--;
				B[i] = 0;
			}
		}
		cnt = m;
		for(int i = n-1; i >= 0; --i){
			if(cnt == 0) break;
			if(B[i] == 0){
				cnt--;
				B[i] = 1;
			}
		}
		FOR(i, n-1){
			if(B[i] > B[i+1]) return false;
		}
		return true;
	};

	int left = 0;
	int right = n+2;
	while(left < right){
		int mid = (left + right)/2;
		if(can(mid)) right = mid;
		else left = mid+1;
	}

	std::cout << left << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}