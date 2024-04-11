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
	std::vector<ll> t;
	void build(int size){
		bottom = 1;
		while(bottom < size) bottom <<= 1;
		t.resize(bottom*2);
	}

	void add(int v, ll a){
		v += bottom;
		t[v] += a;
		while(v > 1){
			v >>= 1;
			t[v] += a;
		}
	}

	ll query(int a, int b){
		if(a > b) return 0ll;
		a += bottom;
		b += bottom+1;
		ll sum = 0;
		while(a < b){
			if(a & 1) sum += t[a++];
			if(b & 1) sum += t[--b];
			a >>= 1; b >>= 1;
		}
		return sum;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	std::set<int> set;
	FOR(i, n) std::cin >> A[i], set.insert(A[i]);
	std::map<int, int> map;
	int kt = 0;
	TRAV(i, set) map[i] = kt++;
	TRAV(i, A) i = map[i];
	Tree tree[2];
	tree[0].build(n+5);
	tree[1].build(n+5);
	ll ans = 0;
	FOR(i, n){
		ans += tree[1].query(A[i]+1, n);
		tree[1].add(A[i], tree[0].query(A[i]+1, n));
		tree[0].add(A[i], 1);
	}
	std::cout << ans;
	return 0;
}