#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void ans(bool co){
	if(co) std::cout << "YES\n";
	else std::cout << "NO\n";
	std::exit(0);
}

int n;
std::vector<std::set<int>> g;
std::vector<int> fib;

int NEED;
PII dwa;
int dfs(int v, int par=-1){
	int sz = 1;
	TRAV(ch, g[v]) if(ch != par){
		int cur = dfs(ch, v);
		if(cur == -1) return -1;
		if(cur == NEED){
			dwa = MP(v, ch);
			return -1;
		}
		sz += cur;
	}
	return sz;
}

void lec(int v, int pos){
	if(pos <= 1) return;
	NEED = fib[pos-2];
	dwa = MP(-1, -1);
	if(dfs(v) != -1){
		NEED = fib[pos-1];
		if(dfs(v) != -1){
			ans(false);
		}
		std::swap(dwa.X, dwa.Y);
	}
	g[dwa.X].erase(dwa.Y);
	g[dwa.Y].erase(dwa.X);
	int fs = dwa.X;
	int sc = dwa.Y;
	lec(fs, pos-1);
	lec(sc, pos-2);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	fib.push_back(1);
	fib.push_back(1);
	while(fib.back() < 100000000){
		int xd = fib[SZ(fib)-2] + fib.back();
		fib.push_back(xd);
	}

	std::cin >> n;

	int pos = 0;
	while(fib[pos] < n) pos++;
	if(fib[pos] > n) ans(false);

	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	
	lec(0, pos);
	ans(true);

	return 0;
}