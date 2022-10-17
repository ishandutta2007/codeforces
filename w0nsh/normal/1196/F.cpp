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

const ll INF = 100000000000000000ll;
int n, m, k;
std::vector<std::map<int, ll> > g;
// std::set<PR<ll, PII> > edges;
std::priority_queue<PR<ll, PII> > edges;
std::set<PII> was;
std::multiset<ll> my;

inline ll mylast(){
	while(SZ(my) > 403) my.erase(std::next(my.end(), -1));
	if(SZ(my) == 403) return *std::next(my.end(), -1);
	return INF;
}

inline PII pr(int a, int b){
	return MP(std::min(a, b), std::max(a, b));
}

ll costif(PII pr){
	if(g[pr.X].count(pr.Y) == 0) return INF;
	return g[pr.X][pr.Y];
}

ll get(){
	PII p = MP(-1, -1);
	while(was.count(p)){
		assert(SZ(edges) > 0);
		p = edges.top().Y;
		edges.pop();
	}
	was.insert(p);
	int a = p.X;
	int b = p.Y;
	ll c = g[a][b];
	g[a].erase(b);
	g[b].erase(a);
	TRAV(i, g[a]){
		PII np = pr(b, i.X);
		ll cif = costif(np);
		if(mylast() > i.Y+c && was.count(np) == 0 && cif > i.Y+c){
			edges.push(MP(-(i.Y+c), np));
			g[b][i.X] = i.Y+c;
			g[i.X][b] = i.Y+c;
			my.insert(i.Y+c);
		}
	}
	TRAV(i, g[b]){
		PII np = pr(a, i.X);
		ll cif = costif(np);
		if(mylast() > i.Y+c && was.count(np) == 0 && cif > i.Y+c){
			edges.push(MP(-(i.Y+c), np));			
			g[a][i.X] = i.Y+c;
			g[i.X][a] = i.Y+c;
			my.insert(i.Y+c);
		}
	}
	// g[a][b] = c;
	// g[b][a] = c;
	return c;
}

int main(){
	was.insert(MP(-1, -1));
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	g.resize(n);
	FOR(i, m){
		int a, b;
		ll c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a][b] = c;
		g[b][a] = c;
		edges.push(MP(-c, pr(a, b)));
		my.insert(c);
	}
	while(--k){
		get();
	}
	std::cout << get() << "\n";
	return 0;
}