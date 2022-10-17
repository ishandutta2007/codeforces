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

std::vector<VI> g;
VI A;
VI col;

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

void fix(int v, int c, int par=-1){
	if(col[v] >= c) col[v]++;
	TRAV(ch, g[v]) if(ch != par){
		fix(ch, c, v);
	}
}
void add(int v, int ile, int par=-1){
	col[v] += ile;
	TRAV(ch, g[v]) if(ch != par) add(ch, ile, v);
}

int dfs(int v, int par=-1){
	int sz = 0;
	TRAV(ch, g[v]) if(ch != par){
		int xd = dfs(ch, v);
		add(ch, sz, v);
		sz += xd;
	}
	if(A[v] > sz) fail();
	col[v] = A[v];
//	std::cout << "col " << v << " " << col[v] << std::endl;
	fix(v, col[v], par);
	col[v]--;
	return sz+1;
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	g.resize(n);
	A.resize(n);
	col.resize(n);
	int root = -1;
	FOR(i, n){
		int p;
		std::cin >> p >> A[i];
		if(p == 0) root = i;
		else{
			p--;
			g[p].push_back(i);
			g[i].push_back(p);
		}
	}
	dfs(root);
	std::cout << "YES\n";
	TRAV(i, col) std::cout << i+1 << " ";
	return 0;
}