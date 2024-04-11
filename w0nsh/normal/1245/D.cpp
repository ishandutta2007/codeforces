#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int repr[2005];
int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}
int Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return 0;
	repr[a] = b;
	return 1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::vector<PII> A;
	std::cin >> n;
	VI C(n), K(n);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(a, b));
	}
	FOR(i, n) std::cin >> C[i];
	FOR(i, n) std::cin >> K[i];
	ll ans = 0;
	std::vector<PR<ll, PII> > edge;
	FOR(i, n){
		REP(j, i+1, n){
			ll cost = 1ll*(K[i]+K[j])*(std::abs(A[i].X-A[j].X) + std::abs(A[i].Y-A[j].Y));
			edge.push_back(MP(cost, MP(i, j)));
		}
		edge.push_back(MP(C[i], MP(i, n)));
	}
	std::sort(edge.begin(), edge.end());
	FOR(i, n+1) repr[i] = i;
	VI V;
	std::vector<PII> con;
	TRAV(ed, edge){
		if(Union(ed.Y.X, ed.Y.Y)){
			ans += ed.X;
			if(ed.Y.Y == n){
				V.push_back(ed.Y.X);
			}else{
				con.push_back(MP(ed.Y.X, ed.Y.Y));
			}
		}
	}
	std::cout << ans << "\n";
	std::cout << SZ(V) << "\n";
	TRAV(i, V) std::cout << i+1 << " ";
	std::cout << "\n";
	std::cout << SZ(con) << "\n";
	TRAV(i, con) std::cout << i.X+1 << " " << i.Y+1 << "\n";
	return 0;
}