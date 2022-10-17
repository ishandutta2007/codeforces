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

struct MaxTree{
	int BOTTOM;
	VI t;
	void build(VI &a){
		BOTTOM = 1;
		while(BOTTOM < SZ(a)) BOTTOM *= 2;
		t.resize(BOTTOM*2, -1000000005);
		FOR(i, SZ(a)) t[i+BOTTOM] = a[i];
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::max(t[i<<1], t[(i<<1)+1]);
	}
	int query(int a, int b){
		int mx = -1000000005;
		a += BOTTOM;
		b += BOTTOM+1;
		while(a < b){
			if(a&1) mx = std::max(mx, t[a++]);
			if(b&1) mx = std::max(mx, t[--b]);
			a>>=1;b>>=1;
		}
		assert(mx != -1000000005);
		return mx;
	}
};

struct Tree{
	int BOTTOM;
	std::vector<ll> t;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t.resize(BOTTOM*2);
	}
	void add(int a, int b, int sum){
		a += BOTTOM;
		b += BOTTOM+1;
		while(a < b){
			if(a&1) t[a++] += sum;
			if(b&1) t[--b] += sum;
			a>>=1;b>>=1;
		}
	}
	ll query(int a){
		ll ans = 0;
		a += BOTTOM;
		while(a > 0){
			ans += t[a];
			a >>= 1;
		}
		return ans;
	}

};

int ile, w;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> ile >> w;
	Tree t;
	t.build(w);
	FOR(_, ile){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		MaxTree tree;
		tree.build(A);
		PII all = MP(n, w-n-1);
		if(all.X <= all.Y) t.add(all.X, all.Y, std::max(0, tree.query(0, n-1)));
		int zer = w-n;
		FOR(i, n){
			int co = tree.query(std::max(0, i-zer), i);
			if(i < zer) co = std::max(co, 0);
			t.add(i, i, co);
		}
		FOR(i, std::min(zer, n)){
			int co = tree.query(n-1-i, std::min(n-1, n-1-i+zer));
			co = std::max(co, 0);
			t.add(w-1-i, w-1-i, co);
		}
	}
	FOR(i, w) std::cout << t.query(i) << " ";
	return 0;
}