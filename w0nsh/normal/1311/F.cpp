#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


struct Tree{
	int BOTTOM;
	std::vector<ll> sum, ile;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		sum.resize(BOTTOM*2);
		ile.resize(BOTTOM*2);
	}
	void add(int v, int a){
		v += BOTTOM;
		while(v >= 1){
			sum[v] += a;
			ile[v]++;
			v>>=1;
		}
	}
	PR<ll, ll> query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		ll x = 0, y = 0;
		while(a < b){
			if(a&1) x += sum[a], y += ile[a], a++;
			if(b&1) --b, x += sum[b], y += ile[b];
			a>>=1;b>>=1;
		}
		return MP(x, y);
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X;
	FOR(i, n) std::cin >> A[i].Y;
	std::sort(A.begin(), A.end());
	std::vector<PII> B(n);
	{
		std::map<int, int> map;
		std::set<int> set;
		TRAV(i, A) set.insert(std::abs(i.Y));
		int fre = 0;
		TRAV(i, set) map[i] = fre++;
		FOR(i, n){
			B[i] = MP(map[std::abs(A[i].Y)], (int)(A[i].Y>=0));
		}
	}
	Tree lef, rig;
	lef.build(n+1);
	rig.build(n+1);
	ll ans = 0;
	FOR(i, n){
		if(B[i].Y){
			ans += rig.query(0, B[i].X).Y*A[i].X-rig.query(0, B[i].X).X;
			ans += lef.query(0, n).Y*A[i].X-lef.query(0, n).X;
			rig.add(B[i].X, A[i].X);
		}else{
			ans += lef.query(B[i].X, n).Y*A[i].X-lef.query(B[i].X, n).X;
			//ans += rig.query(0, n).Y*A[i].X-rig.query(0, n).X;
			lef.add(B[i].X, A[i].X);
		}
	}
	std::cout << ans;
	

	return 0;
}