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

	int n, k;
	std::cin >> n >> k;
	std::vector<PII> A(n*k);
	FOR(i, n*k){
		std::cin >> A[i].X;
		A[i].X--;
		A[i].Y = i;
	}

	int moge = (n + (k-2)) / (k-1);

	std::vector<PII> ans(n);
	VI ile(n*k);

	int from = 0;

	FOR(_, n){
		VI fs(n, -1), sc(n, -1);
		PII pr = MP(-1, -1);
		int col = -1;
		FOR(i, SZ(A)){
			if(fs[A[i].X] == -1) fs[A[i].X] = A[i].Y;
			else if(sc[A[i].X] == -1){
				sc[A[i].X] = A[i].Y;
				pr = MP(fs[A[i].X], sc[A[i].X]);
				col = A[i].X;
				break;
			}
		}
		assert(pr.X != -1);

		REP(i, pr.X, pr.Y+1){
			ile[i]++;
			if(ile[i] == moge){
				from = std::max(from, i+1);
			}
		}
		ans[col] = pr;

		std::vector<PII> B;
		TRAV(x, A){
			if(x.Y < from || x.X == col) continue;
			B.push_back(x);
		}
		A = B;
	}

	FOR(i, n) std::cout << ans[i].X+1 << " " << ans[i].Y+1 << "\n";

	return 0;
}