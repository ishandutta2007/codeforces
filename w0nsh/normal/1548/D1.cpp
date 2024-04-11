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

int cnt[2][2][2];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<PII> A(n);
	FOR(i, n){
		std::cin >> A[i].X >> A[i].Y;
		A[i].X = (A[i].X / 2) % 2;
		A[i].Y = (A[i].Y / 2) % 2;
	}

	ll ans = 0;
	ll hehe = 0;
	FOR(i, n){
		FOR(a, 2) FOR(b, 2) FOR(c, 2) cnt[a][b][c] = 0;
		FOR(j, n) if(i != j){
			int co = ((A[j].X ^ A[i].X) == 0 && (A[j].Y ^ A[i].Y) == 0 ? 0 : 1);
			cnt[co][A[j].X ^ A[i].X][A[j].Y ^ A[i].Y]++;
		}
		FOR(a1, 2) FOR(b1, 2) FOR(c1, 2)
		FOR(a2, 2) FOR(b2, 2) FOR(c2, 2){
			int mam = a1 ^ a2 ^ ((b1 ^ b2) == 0 && (c1 ^ c2) == 0 ? 0 : 1);
			if(mam == 0){
				if(a1 == a2 && b1 == b2 && c1 == c2){
					ans += 1ll * cnt[a1][b1][c1] * (cnt[a2][b2][c2] - 1) / 2;
				}else{
					hehe += 1ll * cnt[a1][b1][c1] * cnt[a2][b2][c2];
				}
			}
		}
	}

	assert(((ans + hehe / 2)) % 3 == 0);
	std::cout << (ans + hehe / 2) / 3 << "\n";

	return 0;
}