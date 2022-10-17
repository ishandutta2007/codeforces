#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto& i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
using ll = long long;
using VI = std::vector<int>;
using PII = std::pair<ll, ll>;

PII kobor(PII a){
	return MP(a.X-a.Y, a.X+a.Y);
}

struct Tree{
	std::vector<int> t;
	int BOTTOM;

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = VI(BOTTOM * 2);
	}

	int query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		int ret = 0;
		while(a < b){
			if(a&1) ret = std::max(ret, t[a++]);
			if(b&1) ret = std::max(ret, t[--b]);
			a>>=1;b>>=1;
		}
		return ret;
	}

	void set(int a, int v){
		a += BOTTOM;
		assert(v >= t[a]);
		t[a] = v;
		while(a > 1){
			a>>=1;
			t[a] = std::max(t[a<<1], t[(a<<1)+1]);
		}
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, V;
	std::cin >> n >> V;
	std::vector<PR<PR<ll, ll>, int>> A(n);
	FOR(i, n) std::cin >> A[i].X.Y, A[i].X.Y *= V, A[i].Y = i;
	FOR(i, n) std::cin >> A[i].X.X;
	FOR(i, n) A[i].X = kobor(A[i].X);
	FOR(i, n) A[i].X.Y *= -1;
	++n;
	A.push_back(MP(MP(0, 0), n-1));


	std::vector<ll> vals;
	FOR(i, n) vals.push_back(A[i].X.Y);
	std::sort(vals.begin(), vals.end());
	auto kto = [&](ll v){
		auto it = std::lower_bound(vals.begin(), vals.end(), v);
		return (int)std::distance(vals.begin(), it);
	};
	FOR(i, n) A[i].X.Y = kto(A[i].X.Y);
	std::sort(A.begin(), A.end());

	Tree tree;
	tree.build(SZ(vals));
	FOR(i, n){
		int heh = tree.query(0, A[i].X.Y);
		if(A[i].Y == n-1){
			std::cout << heh << "\n";
			return 0;
		}
		tree.set(A[i].X.Y, heh + 1);
	}

	return 0;
}