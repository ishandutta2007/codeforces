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

const int MOD = 1000000009;
const int rt5 = 383008016;
int A, B, C;
int BP[300005], CP[300005];
int IBP, ICP;

int modpow(int a, int e){
	if(e == 0) return 1;
	int t = modpow(a, e/2);
	if(e & 1) return (1ll*((1ll*t*t)%MOD)*a)%MOD;
	return (1ll*t*t)%MOD;
}

int geob(int len){
	return (1ll*(1-BP[len])*IBP)%MOD;
}

int geoc(int len){
	return (1ll*(1-CP[len])*ICP)%MOD;
}

struct Tree{
	int BOTTOM;
	VI t;
	std::vector<PII> u;
	void build(VI vec){
		BOTTOM = 1;
		while(BOTTOM < SZ(vec)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
		FOR(i, SZ(vec)) t[i+BOTTOM] = vec[i];
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = (t[i<<1]+t[(i<<1)+1])%MOD;
		}
	}
	void upd(int v, int len){
		if(u[v].X != 0){
			if(v < BOTTOM){
				u[v<<1].X = (u[v<<1].X+u[v].X)%MOD;
				u[(v<<1)+1].X = (1ll*u[(v<<1)+1].X + 1ll*u[v].X*BP[len/2])%MOD;
			}
			t[v] = (1ll*t[v] + 1ll*geob(len)*u[v].X)%MOD;
			u[v].X = 0;
		}
		if(u[v].Y != 0){
			if(v < BOTTOM){
				u[v<<1].Y = (u[v<<1].Y+u[v].Y)%MOD;
				u[(v<<1)+1].Y = (1ll*u[(v<<1)+1].Y + 1ll*u[v].Y*CP[len/2])%MOD;
			}
			t[v] = (1ll*t[v] - 1ll*geoc(len)*u[v].Y)%MOD;
			u[v].Y = 0;
		}
	}
	void add(int a, int b, int from, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v, (hi-lo+1));
		if(a > b) return;
		if(a == lo && b == hi){
			u[v].X = (1ll*A*BP[from] + u[v].X)%MOD;
			u[v].Y = (1ll*A*CP[from] + u[v].Y)%MOD;
			upd(v, (hi-lo+1));
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), from, v<<1, lo, mid);
		add(std::max(a, mid+1), b, from+std::max(0, (std::min(b, mid)-a+1)), (v<<1)+1, mid+1, hi);
		t[v] = (t[v<<1]+t[(v<<1)+1])%MOD;
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v, (hi-lo+1));
		if(a>b) return 0;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return (query(a, std::min(b, mid), v<<1, lo, mid)
				+ query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi))%MOD;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	A = (1ll*rt5*modpow(5, MOD-2))%MOD;
	B = (1ll*(1+rt5)*modpow(2, MOD-2))%MOD;
	C = (1ll*(1-rt5)*modpow(2, MOD-2))%MOD + MOD;
	FOR(i, 300005) BP[i] = modpow(B, i);
	FOR(i, 300005) CP[i] = modpow(C, i);
	IBP = modpow(1-B, MOD-2);
	ICP = modpow(1-C, MOD-2);
	int n, m;
	std::cin >> n >> m;
	VI vec(n);
	FOR(i, n) std::cin>> vec[i];
	Tree tree;
	tree.build(vec);
	FOR(i, m){
		int what;
		std::cin >> what;
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(what == 1){
			tree.add(a, b, 1);
		}else{
			int ans = tree.query(a, b);
			if(ans < 0) ans += MOD;
			std::cout << ans << "\n";
		}
	}
	return 0;
}