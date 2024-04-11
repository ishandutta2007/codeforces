#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct SumTree{
	int BOTTOM;
	std::vector<ll> t;

	void build(std::vector<ll> A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t = std::vector<ll>(BOTTOM*2);
		FOR(i, SZ(A)) t[i+BOTTOM] = A[i];
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = t[i<<1] + t[(i<<1)+1];
		}
	}

	ll query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		ll ret = 0;
		while(a < b){
			if(a&1) ret += t[a++];
			if(b&1) ret += t[--b];
			a>>=1;b>>=1;
		}
		return ret;
	}
};

constexpr ll INF = 1000000666ll*1000000000ll;

struct MinTree{
	int BOTTOM;
	std::vector<ll> t;

	void build(std::vector<ll> A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t = std::vector<ll>(BOTTOM*2, INF);
		FOR(i, SZ(A)) t[i+BOTTOM] = A[i];
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = std::min(t[i<<1], t[(i<<1)+1]);
		}
	}

	ll query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		ll ret = INF;
		while(a < b){
			if(a&1) ret = std::min(t[a++], ret);
			if(b&1) ret = std::min(t[--b], ret);
			a>>=1;b>>=1;
		}
		return ret;
	}
};

struct MaxTree{
	int BOTTOM;
	std::vector<ll> t;

	void build(std::vector<ll> A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t = std::vector<ll>(BOTTOM*2, -INF);
		FOR(i, SZ(A)) t[i+BOTTOM] = A[i];
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = std::max(t[i<<1], t[(i<<1)+1]);
		}
	}

	ll query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		ll ret = -INF;
		while(a < b){
			if(a&1) ret = std::max(t[a++], ret);
			if(b&1) ret = std::max(t[--b], ret);
			a>>=1;b>>=1;
		}
		return ret;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<ll> A(n);
	FOR(i, n){
		std::cin >> A[i];
	}

	FOR(i, n){
		int b;
		std::cin >> b;
		A[i] -= b;
	}

	SumTree sum;
	sum.build(A);

	std::vector<ll> pref(n+1);
	REP(i, 1, n+1) pref[i] = pref[i-1] + A[i-1];

	std::vector<ll> suf(n+1);
	for(int i = n-1; i >= 0; --i) suf[i] = A[i] + suf[i+1];

	MaxTree maxpref;
	maxpref.build(pref);
	MinTree minpref;
	minpref.build(pref);

	MinTree minsuf;
	minsuf.build(suf);
	MaxTree maxsuf;
	maxsuf.build(suf);

	std::vector<ll> hehe(n);
	FOR(i, n) hehe[i] = std::abs(A[i]);

	MaxTree hehetree;
	hehetree.build(hehe);

	FOR(_, q){
		int l, r;
		std::cin >> l >> r;
		l--;r--;

		if(sum.query(l, r) != 0){
			std::cout << -1 << "\n";
		}else{
			bool bad = false;
			ll p = pref[l];
			ll mx = maxpref.query(l+1, r+1);
			if(mx - p > 0) bad = true;

			ll o = suf[r+1];
			ll mn = minsuf.query(l, r);
			if(mn - o < 0) bad = true;

			if(bad) std::cout << -1 << "\n";
			else std::cout << std::max(maxsuf.query(l, r) - o, -(minpref.query(l+1, r+1) - p)) << "\n";
		}
	}

	return 0;
}