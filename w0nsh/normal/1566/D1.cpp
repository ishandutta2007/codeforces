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
		int n, m;
		std::cin >> n >> m;

		std::vector<PII> A(m);
		FOR(i, m){
			std::cin >> A[i].X;
			A[i].Y = i;
		}

		std::sort(A.begin(), A.end(), [&](auto a, auto b){
			if(a.X == b.X) return a.Y > b.Y;
			return a.X < b.X;
		});

		int ans = 0;
		FOR(i, SZ(A)){
			REP(j, i+1, SZ(A)){
				if(A[i].Y < A[j].Y){
					ans++;
				}
			}
		}
		std::cout << ans << "\n";

	}

	return 0;
}