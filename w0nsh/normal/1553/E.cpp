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
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);


	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		VI A(n);
		VI where(n);
		FOR(i, n){
			std::cin >> A[i];
			A[i]--;
			where[A[i]] = i;
		}

		auto check = [&](int k){
			VI perm(n);
			FOR(i, n){
				int want = (i - k + n) % n;
				perm[i] = where[want];
			}

			std::vector<bool> vis(n);
			int xd = 0;
			FOR(i, n){
				if(vis[i]) continue;
				int pos = i;
				int len = 0;
				do{
					len++;
					vis[pos] = true;
					pos = perm[pos];
				}while(pos != i);

				xd += len-1;
			}

			if(xd <= m){
				return true;
			}
			return false;
		};

		std::uniform_int_distribution<int> los(0, n-1);

		VI ans;
		FOR(_, 50){
			int pos = los(rng);
			int shift = (pos - A[pos] + n)%n;
			if(check(shift)) ans.push_back(shift);
		}

		std::sort(ans.begin(), ans.end());
		ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
		std::cout << SZ(ans);
		TRAV(i, ans) std::cout << " " << i;
		std::cout << "\n";
	}

	return 0;
}