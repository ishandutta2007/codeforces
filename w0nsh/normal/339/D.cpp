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

struct Tree{
	int bottom;
	VI t;

	int prop(int v){
		if(v >= bottom) return 1;
		int what = prop(v<<1);
		prop((v<<1)+1);
		if(what) t[v] = (t[v<<1] | t[(v<<1)+1]);
		else t[v] = (t[v<<1] ^ t[(v<<1)+1]);
		return 1-what;
	}

	void build(const VI &a){
		bottom = 1;
		while(bottom < SZ(a)) bottom <<= 1;
		t.resize(2*bottom);
		FOR(i, SZ(a)) t[bottom+i] = a[i];
		prop(1);
	}

	void set(int v, int a){
		v += bottom;
		int what = 1;
		t[v] = a;
		while(v > 1){
			v >>= 1;
			if(what) t[v] = (t[v<<1] | t[(v<<1)+1]);
			else t[v] = (t[v<<1] ^ t[(v<<1)+1]);
			what = 1-what;
		}
	}

	int query(){
		return t[1];
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	VI A(1<<n);
	FOR(i, 1<<n) std::cin >> A[i];
	Tree tree;
	tree.build(A);
	FOR(_, m){
		int a, b;
		std::cin >> a >> b;
		a--;
		tree.set(a, b);
		std::cout << tree.query() << "\n";
	}
	return 0;
}