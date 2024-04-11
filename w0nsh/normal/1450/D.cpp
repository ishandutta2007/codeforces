#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i], A[i]--;
		VI cnt(n);
		FOR(i, n) cnt[A[i]]++;
		std::vector<bool> ans(n+1);
		bool good = true;
		FOR(i, n) if(cnt[i] != 1) good = false;
		if(good) ans[1] = true;
		int l = 0;
		int r = n-1;
		FOR(i, n-1){
			if(cnt[i] == 0) break;
			ans[n-i] = true;
			if(cnt[i] > 1){
				break;
			}
			if(A[l] != i && A[r] != i){
				break;
			}
			if(A[l] == i) l++;
			else if(A[r] == i) r--;
		}
		FOR(i, n) if(ans[i+1]) std::cout << 1;
			else std::cout << 0;
		std::cout << "\n";
	}

	return 0;
}