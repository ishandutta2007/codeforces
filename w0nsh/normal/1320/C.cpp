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

const int INF = 1000000666;
const ll LINF = 1000000000ll*1000000000ll;

struct MaxTree{
	int BOTTOM;
	std::vector<ll> t, u;
	void build(VI A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t.resize(BOTTOM*2, -LINF);
		u.resize(BOTTOM*2, 0);
		FOR(i, SZ(A)) t[BOTTOM+i] = -A[i];
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::max(t[i<<1], t[(i<<1)+1]);
	}
	void upd(int v){
		t[v] += u[v];
		if(v < BOTTOM){
			u[v<<1] += u[v];
			u[(v<<1)+1] += u[v];
		}
		u[v] = 0;
	}
	ll query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return -LINF;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return std::max(query(a, std::min(b, mid), v<<1, lo, mid),
						query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
	void update(int a, int b, ll w, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return;
		if(a == lo && b == hi){
			u[v] += w;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		update(a, std::min(b, mid), w, v<<1, lo, mid);
		update(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		t[v] = std::max(t[v<<1], t[(v<<1)+1]);
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, p;
	std::cin >> n >> m >> p;
	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;
	std::vector<PII> B(m);
	FOR(i, m) std::cin >> B[i].X >> B[i].Y;
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	std::vector<PR<int, PII> > M;
	FOR(i, p){
		int x, y, z;
		std::cin >> x >> y >> z;
		M.push_back(MP(x, MP(y, z)));
	}
	std::sort(M.begin(), M.end());
	MaxTree tree;
	VI xd;
	FOR(i, SZ(B)) xd.push_back(B[i].Y);
	tree.build(xd);
	ll ans = -LINF;
	auto it = M.begin();
	TRAV(a, A){
		while(it != M.end() && it->X < a.X){
			int ps = std::lower_bound(B.begin(), B.end(), MP(it->Y.X, 1000000005))-B.begin();
			if(ps <= SZ(B)-1) tree.update(ps, SZ(B)-1, it->Y.Y);
			it++;
		}
		ans = std::max(ans, tree.query(0, SZ(B)-1)-a.Y);
	}
	std::cout << ans;

	return 0;
}