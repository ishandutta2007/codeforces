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

struct UF{
	VI repr;
	void Init(int n){
		repr.resize(n);
		std::iota(repr.begin(), repr.end(), 0);
	}
	int Find(int a){
		if(a == repr[a]) return a;
		return repr[a] = Find(repr[a]);
	}
	bool Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if(a == b) return false;
		repr[a] = b;
		return true;
	}
};

int n, m;
std::vector<VI> g, non;
VI pre, post;
int tick;

void dfs(int v){
	pre[v] = tick++;
	TRAV(ch, g[v]){
		if(pre[ch] == -1) dfs(ch);
	}
	post[v] = tick++;
}

VI add;

bool inside(int a, int b){
	return pre[a] >= pre[b] && post[a] <= post[b];
}

std::vector<VI> dupa;

void jazda(int v, int par=-1){
	TRAV(ch, non[v]){
		int a = v;
		int b = ch;
		if(inside(a, b)) std::swap(a, b);
		if(inside(b, a)){
			// a na gorze
			add[0] += 1;
			dupa[b].push_back(a);
			// add[poda] += -1;
			add[b] += 1;
		}else{
			add[a] += 1;
			add[b] += 1;
		}
	}
	TRAV(ch, g[v]){
		if(ch != par) jazda(ch, v);
	}
}

VI ans;
void wez(int v, int val=0, int par=-1){
	val += add[v];
	ans[v] = val;

	TRAV(ch, g[v]){
		if(ch == par) continue;
		wez(ch, val, v);
	}
}

VI dokogo;

void hehe(int v, int par=-1){
	TRAV(wyz, dupa[v]){
		add[dokogo[wyz]] += -1;
	}

	TRAV(ch, g[v]) if(ch != par){
		dokogo[v] = ch;
		hehe(ch, v);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	UF uf;
	uf.Init(n);
	g.resize(n);
	non.resize(n);
	int need = 0;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(!uf.Union(a, b)){
			// non[a].push_back(b);
			non[b].push_back(a);
			need++;
		}else{
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}

	pre.assign(n, -1);
	post.assign(n, -1);
	dfs(0);

	dupa.resize(n);
	add.resize(n);
	jazda(0);

	dokogo.resize(n);
	hehe(0);

	ans.resize(n);
	wez(0);

	FOR(i, n) std::cout << (ans[i] == need ? 1 : 0);
	std::cout << "\n";

	return 0;
}