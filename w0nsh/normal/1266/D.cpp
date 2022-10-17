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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<ll> ile(n);
	FOR(i, m){
		int a, b, d;
		std::cin >> a >> b >> d;
		a--;b--;
		ile[a] -= d;
		ile[b] += d;
	}
	std::vector<PR<ll, int> > give, take;
	FOR(i, n){
		if(ile[i] < 0) give.push_back(MP(-ile[i], i));
		else if(ile[i] > 0) take.push_back(MP(ile[i], i));
	}
	//std::sort(give.begin(), give.end());
	//std::sort(take.begin(), take.end());
	int p1 = 0;
	int p2 = 0;
	std::vector<PR<PII, ll> > edges;
	while(p1 < SZ(take) && p2 < SZ(give)){
		ll co = std::min(take[p1].X, give[p2].X);
		take[p1].X -= co;
		give[p2].X -= co;
		edges.push_back(MP(MP(give[p2].Y, take[p1].Y), co));
		if(take[p1].X == 0) p1++;
		if(give[p2].X == 0) p2++;
	}
	std::cout << SZ(edges) << "\n";
	TRAV(i, edges) std::cout << i.X.X+1 << " " << i.X.Y+1 << " " << i.Y << "\n";
	return 0;
}