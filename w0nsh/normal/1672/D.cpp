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


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n), B(n);
		FOR(i, n) std::cin >> A[i];
		FOR(i, n) std::cin >> B[i];
		
		int j = 0;
		VI cnt(n+1);
		int last = -1;
		bool bad = false;

		FOR(i, n){
			if(B[i] == last && cnt[B[i]]){
				cnt[B[i]]--;
				continue;
			}

			while(j < n && A[j] != B[i]){
				cnt[A[j]]++;
				++j;
			}
			if(j == n){
				bad = true;
				break;
			}
			last = A[j];
			++j;
		}

		FOR(i, n+1) if(cnt[i]) bad = true;

		std::cout << (bad ? "NO\n" : "YES\n");
	}

	return 0;
}