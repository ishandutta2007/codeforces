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

std::vector<std::vector<PII> > g;
std::vector<ll> ans;

int repr[100005];
std::set<int> sets[100005];

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}
void Union(int a, int b, ll wag){
	a = Find(a);
	b = Find(b);
	if(SZ(sets[a]) > SZ(sets[b])) std::swap(a, b);
	TRAV(i, sets[a]){
		if(sets[b].count(i) != 0){
			ans[i] = wag;
		}else sets[b].insert(i);
	}
	repr[a] = b;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, k, q;
	std::cin >> n >> m >> k >> q;
	g.resize(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(MP(b, c));
		g[b].push_back(MP(a, c));
	}
	FOR(i, n) repr[i] = i;
	FOR(i, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		sets[a].insert(i);
		sets[b].insert(i);
	}
	std::vector<ll> dist(n);
	FOR(i, n) dist[i] = 1000000000ll*1000000000ll;
	FOR(i, k) dist[i] = 0ll;
	std::priority_queue<PR<ll, PII> > que;
	FOR(i, k) que.push(MP(0ll, MP(i, i)));
	int spoj = 0;
	ans.resize(q);
	while(SZ(que)){
		auto cur = que.top();
		que.pop();
		int v = cur.Y.X;
		//int other = cur.Y.Y;
		//if(Find(v) != Find(other)) Union(v, other, 0);
		TRAV(ch, g[v]){
			if(dist[ch.X] > dist[v]+ch.Y){
				dist[ch.X] = dist[v]+ch.Y;
				que.push(MP(-dist[ch.X], MP(ch.X, v)));
			}
		}
	}
	std::vector<PR<ll, PR<ll, int> > > edges;
	FOR(i, n) TRAV(ch, g[i]){
		edges.push_back(MP(dist[i]+dist[ch.X]+ch.Y, MP(i, ch.X)));
	}
	std::sort(edges.begin(), edges.end());
	TRAV(ed, edges){
		if(Find(ed.Y.X) != Find(ed.Y.Y)) Union(ed.Y.X, ed.Y.Y, ed.X);
	}

	TRAV(i, ans) std::cout << i << "\n";
	return 0;
}