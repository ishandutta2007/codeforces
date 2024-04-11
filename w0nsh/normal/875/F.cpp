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

int repr[200005];
int was[200005];

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b){
		if(!was[a]){
			was[a] = true;
			return true;
		}
		return false;
	}
	if(was[a] && was[b]) return false;

	was[b] = was[a] || was[b];
	repr[a] = b;
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	FOR(i, n) repr[i] = i, was[i] = false;

	std::vector<PR<int, PII> > edges;

	FOR(i, m){
		int a, b, w;
		std::cin >> a >> b >> w;
		a--;b--;
		edges.push_back(MP(w, MP(a, b)));
	}

	std::sort(edges.begin(), edges.end());
	std::reverse(edges.begin(), edges.end());

	int ans = 0;
	TRAV(e, edges){
		if(Union(e.Y.X, e.Y.Y)) ans += e.X;
	}
	
	std::cout << ans << "\n";


	return 0;
}