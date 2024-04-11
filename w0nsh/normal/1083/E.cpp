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
typedef std::pair<ll, ll> PLL;
typedef std::vector<int> VI;

const ll INF = 1000000005ll;
const int MAX = 1<<20;
struct Node{
	int l, r;
	PLL val;
	Node() : l(-1), r(-1), val(MP(-INF, -INF)) {}
	Node(PLL v) : l(-1), r(-1), val(v) {}
	ll at(int x){
		return val.X*x+val.Y;
	}
} tree[(1<<21)+100];
int p[1000005];

ll query(int point, int v=1, int lo=0, int hi=MAX){
	ll ths = tree[v].at(p[point]);
	if(lo+1 == hi) return ths;
	int mid = (lo+hi)/2;
	if(point < mid){
		ths = std::max(ths, query(point, (v<<1), lo, mid));
	}else{
		ths = std::max(ths, query(point, (v<<1)+1, mid, hi));
	}
	return ths;
}

void add(PLL nw, int v=1, int lo=0, int hi=MAX){
	int mid = (lo+hi)/2;
	bool sl = nw.X*p[lo]+nw.Y > tree[v].at(p[lo]);
	bool sm = nw.X*p[mid]+nw.Y > tree[v].at(p[mid]);
	if(sm) std::swap(tree[v].val, nw);
	if(lo+1 == hi) return;
	if(sl != sm){
		add(nw, (v<<1), lo, mid);
	}else{
		add(nw, (v<<1)+1, mid, hi);
	}
}

int n;
std::vector<PR<PII, ll> > A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		ll a, b, c;
		std::cin >> a >> b >> c;
		A.push_back(MP(MP(a, b), c));
	}
	std::sort(A.begin(), A.end());
	FOR(i, n) p[i] = A[i].X.Y;
	add(MP(0, 0));
	ll best = 0;
	FOR(i, n){
		auto a = A[i];
		ll cur = 1ll*a.X.X*a.X.Y - a.Y;
		cur += query(i);
		best = std::max(best, cur);
		add(MP(-a.X.X, cur));
	}
	std::cout << best;
	return 0;
}