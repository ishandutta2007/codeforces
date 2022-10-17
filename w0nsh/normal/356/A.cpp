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

int n;

struct Tree{
	int bottom;
	VI t, tm;

	void build(int size){
		bottom = 1;
		while(bottom < size) bottom *= 2;
		t.resize(2*bottom, -1);
		tm.resize(2*bottom, 1000000000);
	}

	void set(int a, int b, int val, int tick){
		a += bottom;
		b += bottom+1;
		while(a < b){
			if(a & 1){
				if(t[a] == -1) t[a] = val, tm[a] = tick;
				a++;
			}
			if(b & 1){
				if(t[b-1] == -1) t[b-1] = val, tm[b-1] = tick;
				b--;
			}
			a >>= 1; b >>= 1;
		}
	}

	void dfs(int v, int val=-1, int besttm = 1000000000){
		if(t[v] != -1 && tm[v] < besttm) val = t[v], besttm = tm[v];
		if(v >= bottom){
			if(v - bottom < n) std::cout << val+1 << " ";
		}else{
			dfs(v<<1, val, besttm);
			dfs((v<<1)+1, val, besttm);
		}
	}

};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int m;
	std::cin >> n >> m;
	Tree tree;
	tree.build(n);
	int tick = 1;
	FOR(i, m){
		int l, r, x;
		std::cin >> l >> r >> x;
		l--;r--;x--;
		if(x > l) tree.set(l, x-1, x, tick);
		if(x < r) tree.set(x+1, r, x, tick);
		tick++;
	}
	tree.dfs(1);
	return 0;
}