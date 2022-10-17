#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int repr[200005];
VI set[200005];

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}

void Union(int a, int b, VI &jesli){
	a = Find(a);
	b = Find(b);
	if(a == b) return;
	if(SZ(set[a]) > SZ(set[b])) std::swap(a, b);
	TRAV(i, set[a]) set[b].push_back(i);
	jesli = std::move(set[a]);
	repr[a] = b;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, q;
	std::cin >> n >> m >> q;
	VI P(n);
	FOR(i, n) std::cin >> P[i];
	std::vector<PII> edges;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		edges.push_back(MP(a, b));
	}

	std::vector<PII> Q;

	std::vector<bool> deleted(m);
	FOR(i, q){
		int what;
		int v;
		std::cin >> what >> v;
		v--;
		Q.push_back(MP(what, v));
		if(what == 2) deleted[v] = true;
	}

	std::vector<VI> kto(q);

	FOR(i, n) repr[i] = i;
	FOR(i, n) set[i].push_back(i);

	FOR(i, m) if(!deleted[i]){
		VI temp;
		PII ed = edges[i];
		Union(ed.X, ed.Y, temp);
	}

	for(int i = q-1; i >= 0; --i){
		if(Q[i].X == 2){
			PII ed = edges[Q[i].Y];
			Union(ed.X, ed.Y, kto[i]);
		}
	}

	std::vector<std::set<int>* > pt(n);
	std::vector<bool> was(n);
	FOR(i, n){
		int f= Find(i);
		if(was[f]) continue;
		was[f] = true;
		pt[f] = new std::set<int>();
		TRAV(j, set[f]){
			pt[j] = pt[f];
			pt[f]->insert(P[j]);
		}
	}
	
	FOR(i, q){
		int v = Q[i].Y;
		if(Q[i].X == 1){
			if(SZ(*pt[v]) == 0) std::cout << 0 << "\n";
			else{
				auto it = std::prev(pt[v]->end());
				std::cout << *it << "\n";
				pt[v]->erase(it);
			}
		}else{
			if(SZ(kto[i]) == 0) continue;
			int f = kto[i][0];
			auto xd = new std::set<int>();
			TRAV(j, kto[i]){
				if(pt[f]->count(P[j])){
					pt[f]->erase(P[j]);
					xd->insert(P[j]);
				}
			}
			TRAV(j, kto[i]){
				pt[j] = xd;
			}
		}
	}

	return 0;
}