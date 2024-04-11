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

std::ostream & operator <<(std::ostream &stream, const PII &a){
	stream << "(" << a.X << ", " << a.Y << ")";
	return stream;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	std::vector<VI> A(n, VI(m));
	std::vector<std::vector<PII> > repr(n, std::vector<PII>(m));
	std::vector<std::vector<std::vector<PII> > > set(n, std::vector<std::vector<PII> >(m));
	FOR(i, n) FOR(j, m) std::cin >> A[i][j], repr[i][j] = MP(i, j);

	std::function<PII(PII)> Find = [&](PII a){
		if(a == repr[a.X][a.Y]) return a;
		return repr[a.X][a.Y] = Find(repr[a.X][a.Y]);
	};

	auto Union = [&](PII a, PII b){
		a = Find(a);
		b = Find(b);
		if(a == b) return;
		if(SZ(set[a.X][a.Y]) > SZ(set[b.X][b.Y])) std::swap(a, b);
		TRAV(i, set[a.X][a.Y]) set[b.X][b.Y].push_back(i);
		repr[a.X][a.Y] = b;
	};

	std::vector<std::map<int, int> > wiersz;

	FOR(i, n){
		std::map<int, VI> vals;
		FOR(j, m){
			vals[A[i][j]].push_back(j);
		}
		FOR(j, m){
			if(vals[A[i][j]].size() > 1){
				int other = vals[A[i][j]][0];
				if(other == j) other = vals[A[i][j]][1];
				Union(MP(i, other), MP(i, j));
			}
			auto it = vals.upper_bound(A[i][j]);
			if(it != vals.end()){
				PII me = Find(MP(i, j));
				set[me.X][me.Y].push_back(MP(i, it->Y[0]));
			}
		}
	}
	FOR(j, m){
		std::map<int, VI> vals;
		FOR(i, n){
			vals[A[i][j]].push_back(i);
		}
		FOR(i, n){
			if(vals[A[i][j]].size() > 1){
				int other = vals[A[i][j]][0];
				if(other == i) other = vals[A[i][j]][1];
				Union(MP(other, j), MP(i, j));
			}
			auto it = vals.upper_bound(A[i][j]);
			if(it != vals.end()){
				PII me = Find(MP(i, j));
				set[me.X][me.Y].push_back(MP(it->Y[0], j));
			}
		}
	}

	std::vector<bool> vis(n*m);

	/*
	FOR(i, n) FOR(j, m){
		std::cout << i << "," << j << "  ";
		auto ch = Find(MP(i, j));
		std::cout << "FIND " << ch << "  ";
		TRAV(xd, set[ch.X][ch.Y]) std::cout << xd << " ";
		std::cout << std::endl;
	};
*/
	std::vector<PII> topo;
	std::function<void(PII)> dfs = [&](PII v){
		vis[v.X*m+v.Y] = true;
		TRAV(x, set[v.X][v.Y]){
			PII ch = Find(x);
			if(!vis[ch.X*m+ch.Y]) dfs(ch);
		}
		topo.push_back(v);
	};

	FOR(i, n) FOR(j, m){
		auto ch = Find(MP(i, j));
		if(!vis[ch.X*m+ch.Y]) dfs(ch);
	}

	VI val(n*m);

	int mx = 0;


	TRAV(v, topo){
		val[v.X*m+v.Y] = 1;
		TRAV(x, set[v.X][v.Y]){
			auto ch = Find(x);
			val[v.X*m+v.Y] = std::max(val[v.X*m+v.Y], val[ch.X*m+ch.Y]+1);
		}

		mx = std::max(mx, val[v.X*m+v.Y]);
	}

	FOR(i, n){
		FOR(j, m){
			auto ch = Find(MP(i, j));
			std::cout << mx+1-val[ch.X*m+ch.Y] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}