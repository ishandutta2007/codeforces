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



const int INF = 2000000666;

struct MinTree{
	int BOTTOM;
	VI t, vec;
	inline int left(int a){
		return a<<1;
	}
	inline int right(int a){
		return (a<<1)+1;
	}
	inline int parent(int a){
		return a>>1;
	}
	void prop(int v){
		if(v >= BOTTOM) return;
		prop(left(v));
		prop(right(v));
		if(vec[t[left(v)]] < vec[t[right(v)]]) t[v] = t[left(v)];
		else t[v] = t[right(v)];
	}
	void build(VI vc){
		int size = SZ(vc);
		vec = vc;
		BOTTOM = 1;
		while(BOTTOM < size){
			BOTTOM *= 2;
		}
		t.resize(BOTTOM*2);
		FOR(i, size) t[i+BOTTOM] = i;
		REP(i, size, BOTTOM) t[i+BOTTOM] = -1;
		prop(1);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return -1;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		int l = query(a, std::min(b, mid), left(v), lo, mid);
		int r = query(std::max(a, mid+1), b, right(v), mid+1, hi);
		if(r == -1) return l;
		if(l == -1) return r;
		if(vec[l] < vec[r]) return l;
		return r;
	}
};

const int MOD = 998244353;
int n, m;
VI A;
MinTree tree;
int dp[505][505];

int solve(int a, int b){
	if(a >= b) return 1;
	if(dp[a][b] != -1) return dp[a][b];
	int pos = tree.query(a, b);
	int l = 0;
	int r = 0;
	REP(i, a, pos+1) l = (l+((1ll*solve(a, i-1)*solve(i, pos-1))%MOD))%MOD;
	REP(i, pos, b+1) r = (r+((1ll*solve(pos+1, i)*solve(i+1, b))%MOD))%MOD;
	dp[a][b] = (1ll*l*r)%MOD;
	return dp[a][b];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	FOR(i, 505) FOR(j, 505) dp[i][j] = -1;
	std::cin >> n >> m;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	tree.build(A);
	std::cout << solve(0, n-1);
	return 0;
}