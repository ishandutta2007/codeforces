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

const int INF = 1000000666;

struct MinTree{
	int BOTTOM;
	VI t;
	void go(int v){
		if(v >= BOTTOM) return;
		go(v<<1);
		go((v<<1)+1);
		t[v] = std::min(t[v<<1], t[(v<<1)+1]);
	}
	void build(VI arr){
		BOTTOM = 1;
		while(BOTTOM < SZ(arr)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		FOR(i, SZ(arr)) t[BOTTOM+i] = arr[i];
		REP(i, SZ(arr), BOTTOM) t[BOTTOM+i] = INF;
		go(1);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return INF;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return std::min(query(a, std::min(b, mid), v<<1, lo, mid),
						query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
	void update(int v, int val){
		v = BOTTOM+v;
		t[v] = val;
		while(v > 1){
			v = v>>1;
			t[v] = std::min(t[v<<1], t[(v<<1)+1]);
		}
	}
};

int n, m, q;
VI A;

VI parent, next;
std::vector<VI> g;
std::vector<bool> vis;
VI wyn;


void dfs(int v, int lev, int back){
	// std::cout << "in " << v+1 << " lev " << lev << " back " << back << std::endl;
	vis[v] = true;
	if(lev == n){
		wyn[v] = back;
		back = next[back];
	}
	TRAV(ch, g[v]){
		if(ch == parent[v]) continue;
		next[v] = ch;
		dfs(ch, std::min(lev+1, n), back);
	}
	if(lev == n && parent[back] != -1){
		back = parent[back];
	}

}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> q;
	if(n == 1){
		FOR(i, q) std::cout << 1;
		return 0;
	}
	VI rev(n);
	FOR(i, n){
		int a;
		std::cin >> a;
		a--;
		rev[a] = i;
	}
	FOR(i, m){
		int a;
		std::cin >> a;
		a--;
		A.push_back(rev[a]);
	}
	VI last(n, -1);
	parent.resize(m, -1);
	g.resize(m);
	for(int i = m-1; i >= 0; --i){
		int nxt = (A[i]+1)%n;
		if(last[nxt] != -1){
			parent[i] = last[nxt];
			g[i].push_back(last[nxt]);
			g[last[nxt]].push_back(i);
		}
		last[A[i]] = i;
	}
	vis.resize(m);
	next.resize(m);
	wyn.resize(m, 1000000666);
	for(int i = m-1; i >= 0; --i){
		if(!vis[i]){
			dfs(i, 1, i);
		}
	}
	// FOR(i, m) std::cout << wyn[i] << " ";
	MinTree tree;
	tree.build(wyn);
	FOR(i, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(tree.query(a, b) <= b) std::cout << 1;
		else std::cout << 0;
	}
	return 0;
}