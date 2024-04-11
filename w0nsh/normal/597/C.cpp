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
	std::vector<ll> t;
	void build(int v){
		BOTTOM = 1;
		while(BOTTOM < v) BOTTOM *= 2;
		t.resize(BOTTOM*2);
	}
	void add(int v, ll val){
		v += BOTTOM;
		while(v >= 1){
			t[v] += val;
			v >>= 1;
		}
	}
	ll query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		ll sum = 0;
		while(a < b){
			if(a&1) sum += t[a++];
			if(b&1) sum += t[--b];
			a>>=1;b>>=1;
		}
		return sum;
	}
};

Tree t[11];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	ll ans = 0;
	FOR(i, k+1) t[i].build(n+1);
	t[0].add(0, 1);
	FOR(i, n){
		REP(j, 1, k+1){
			t[j].add(A[i], t[j-1].query(0, A[i]-1));
		}
		ans += t[k].query(0, A[i]-1);
	}
	std::cout << ans;
	return 0;
}