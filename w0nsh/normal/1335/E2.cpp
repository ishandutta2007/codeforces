#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
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
		std::vector<VI> pos(200);
		VI next(n, -1), prev(n, -1);
		VI last(200, -1);
		VI first(200, -1);
		FOR(i, n){
			std::cin >> A[i];
			A[i]--;
			pos[A[i]].push_back(i);
			if(last[A[i]] != -1) next[last[A[i]]] = i, prev[i] = last[A[i]];
			last[A[i]] = i;
			if(first[A[i]] == -1) first[A[i]] = i;
		}
		
		auto getmax = [&](int l, int r){
			if(l > r) return 0;
			int mx = 0;
			FOR(i, 200){
				mx = std::max(mx,
					(int)(std::upper_bound(pos[i].begin(), pos[i].end(), r)
					- std::lower_bound(pos[i].begin(), pos[i].end(), l)));
			}
			return mx;
		};

		int ans = 0;
		FOR(i, 200) ans = std::max(ans, SZ(pos[i]));
		FOR(i, 200){
			int l = first[i];
			int r = last[i];
			if(l == -1) continue;
			int have = 2;
			while(l != -1 && r != -1 && l < r){
				ans = std::max(ans, getmax(l+1, r-1)+have);
				l = next[l];
				r = prev[r];
				have+= 2;
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}