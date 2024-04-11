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
	int BOTTOM;
	VI t;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t.resize(BOTTOM*2);
	}
	int query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		int sum = 0;
		while(a < b){
			if(a&1) sum += t[a++];
			if(b&1) sum += t[--b];
			a>>=1;b>>=1;
		}
		return sum;
	}
	void add(int a, int w){
		a += BOTTOM;
		while(a > 0){
			t[a] += w;
			a>>=1;
		}
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		VI A(n);
		VI B(m);
		VI gdzie(n);
		FOR(i, n) std::cin >> A[i];
		FOR(i, m) std::cin >> B[i];
		FOR(i, n){
			A[i]--;
			gdzie[A[i]] = i;
		}
		FOR(i, m) B[i]--;
		Tree tree;
		tree.build(n);
		int mx = 0;
		ll ans = m;
		FOR(i, m){
			int b = gdzie[B[i]];
			tree.add(b, 1);
			if(b < mx) continue;
			mx = b;
			ans += 2*(b-tree.query(0, b)+1);
		}
		std::cout << ans << "\n";
	}
	return 0;
}