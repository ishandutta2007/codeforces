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

const ll INF = 1000000000ll*1000000000ll;



int n, m, repr[300000];
std::vector<ll> cost;
std::vector<PR<ll, PII> > edges;

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}

void Union(int a, int b){
	int ra = Find(a);
	int rb = Find(b);
	if(ra == rb) return;
	repr[rb] = ra;
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	cost.resize(n);
	FOR(i, n) std::cin >> cost[i];
	FOR(i, m){
		int a, b;
		ll w;
		std::cin >> a >> b >> w;
		a--;b--;
		edges.push_back(MP(w, MP(a, b)));
	}
	int min = 0;
	FOR(i, n) if(cost[i] < cost[min]) min = i;
	FOR(i, n) if(i != min) edges.push_back(MP(cost[i] + cost[min], MP(i, min)));
	FOR(i, n) repr[i] = i;
	int ed = 0;
	ll ct = 0;
	std::sort(edges.begin(), edges.end());
	auto it = edges.begin();
	while(ed < n-1){
		if(Find(it->Y.X) != Find(it->Y.Y)){
			ct += it->X;
			Union(it->Y.X, it->Y.Y);
			ed++;
		}
		it++;
	}
	std::cout << ct;
	return 0;
}