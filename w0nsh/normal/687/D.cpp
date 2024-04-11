#pragma GCC optimize "O3"
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

int repr[1005];
int col[1005];
int n;
void Reset(){
	FOR(i, n) repr[i] = i, col[i] = 0;
}
int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}
void Union(int a, int b){
	repr[a] = b;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int m, q;
	std::cin >> n >> m >> q;

	std::vector<PR<PII, PII> > edges;

	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		edges.push_back(MP(MP(c, i), MP(a, b)));
	}

	std::sort(edges.begin(), edges.end());
	std::reverse(edges.begin(), edges.end());

	FOR(_, q){
		int l, r;
		std::cin >> l >> r;
		l--;r--;

		std::vector<PII> edg;
		VI cst;
		edg.reserve(r-l+1);
		cst.reserve(r-l+1);

		Reset();
		int ans = -1;
		FOR(i, m) if(edges[i].X.Y >= l && edges[i].X.Y <= r){
			int a = edges[i].Y.X;
			int b = edges[i].Y.Y;
			int ra = Find(a);
			int rb = Find(b);
			if(ra == rb){
				if(col[a] == col[b]){
					ans = edges[i].X.X;
					break;
				}
			}else{
				if(col[a] == col[b]){
					FOR(j, n) if(Find(j) == ra) col[j] = 1-col[j];
				}
				Union(ra, rb);
			}
		}

		std::cout << ans << "\n";
	}

	return 0;
}