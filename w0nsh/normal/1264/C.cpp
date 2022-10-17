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

const int MOD = 998244353;

int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

VI A, B;

struct Tree{
	int BOTTOM;
	std::vector<PII> t;
	void merg(PII &r, PII &a, PII &b){
		r.X = (1ll*a.X*b.X)%MOD;
		r.Y = (1ll*a.Y*b.X + b.Y)%MOD;
	}
	void build(VI a){
		BOTTOM = 1;
		while(BOTTOM < SZ(a)) BOTTOM *= 2;
		t.resize(BOTTOM*2, MP(0, 0));
		FOR(i, SZ(a)) t[i+BOTTOM] = MP(A[a[i]], A[a[i]]);
		for(int i = BOTTOM-1; i >= 1; --i){
			merg(t[i], t[i<<1], t[(i<<1)+1]);
		}
	}
	PII query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a>b) return MP(1, 0);
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		PII lef = query(a, std::min(b, mid), v<<1, lo, mid);
		PII rig = query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
		PII xd;
		merg(xd, lef, rig);
		return xd;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, q;
	std::cin >> n >> q;
	A.resize(101);
	B.resize(101);
	REP(i, 1, 101){
		int p = (1ll*i*modpow(100, MOD-2))%MOD;
		int r = modpow(p, MOD-2);
		int odw = (MOD+1-p)%MOD;
		int rv = modpow(odw, MOD-2);
		int sum = (1ll*rv*modpow(modpow((rv-1+MOD)%MOD, 2), MOD-2))%MOD;
		sum = (1ll*sum + 1ll*rv*modpow((rv-1+MOD)%MOD, MOD-2))%MOD;
		A[i] = (1ll*sum*p)%MOD;
	}
	A[100] = 1;
	VI p(n);
	FOR(i, n) std::cin >> p[i];
	Tree tree;
	tree.build(p);
	int ans = tree.query(0, n-1).Y;
	std::set<int> set;
	set.insert(0);
	set.insert(n);
	FOR(_, q){
		int a;
		std::cin >> a;
		a--;
		if(set.count(a)){
			auto lef = set.lower_bound(a);
			lef--;
			auto rig = set.upper_bound(a);
			ans = (MOD+ans-tree.query(a, *rig-1).Y)%MOD;
			ans = (MOD+ans-tree.query(*lef, a-1).Y)%MOD;
			ans = (ans+tree.query(*lef, *rig-1).Y)%MOD;
			set.erase(a);
		}else{
			auto lef = set.lower_bound(a);
			lef--;
			auto rig = set.upper_bound(a);
			ans = (MOD+ans-tree.query(*lef, *rig-1).Y)%MOD;
			ans = (ans+tree.query(*lef, a-1).Y)%MOD;
			ans = (ans+tree.query(a, *rig-1).Y)%MOD;
			set.insert(a);
		}
		std::cout << ans << "\n";
	}
	return 0;
}