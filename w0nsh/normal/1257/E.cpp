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

const int INF = 1000000006;

int BOTTOM;
std::vector<int> t, u;

void build(int n){
	BOTTOM = 1;
	while(BOTTOM < n) BOTTOM *= 2;
	t.resize(BOTTOM*2);
	u.resize(BOTTOM*2);
}
void upd(int v){
	if(u[v] != 0){
		t[v] += u[v];
		if(v < BOTTOM){
			u[v<<1] += u[v];
			u[(v<<1)+1] += u[v];
		}
		u[v] = 0;
	}
}
int query(int a, int b, int v=1, int lo=0, int hi=-2){
	if(hi==-2) hi = BOTTOM-1;
	upd(v);
	if(a>b) return INF;
	if(a == lo && b == hi){
		return t[v];
	}
	int mid = (lo+hi)/2;
	return std::min(query(a, std::min(b, mid), v<<1, lo, mid),
					query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
}
void add(int a, int b, int w, int v=1, int lo=0, int hi=-2){
	if(hi==-2) hi = BOTTOM-1;
	upd(v);
	if(a > b) return;
	if(a == lo && b == hi){
		u[v] += w;
		upd(v);
		return;
	}
	int mid = (lo+hi)/2;
	add(a, std::min(b, mid), w, v<<1, lo, mid);
	add(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
	t[v] = std::min(t[v<<1], t[(v<<1)+1]);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int a, b, c;
	std::cin >> a >> b >> c;
	VI A(a+b+c);
	FOR(i, a){
		int x;
		std::cin >> x;
		x--;
		A[x] = 0;
	}
	FOR(i, b){
		int x;
		std::cin >> x;
		x--;
		A[x] = 1;
	}
	FOR(i, c){
		int x;
		std::cin >> x;
		x--;
		A[x] = 2;
	}
	int n = a+b+c;
	VI noone(n+1);
	REP(i, 1, n+1) noone[i] = noone[i-1] + (A[i-1] == 1 ? 0 : 1);
	VI notwo(n+1);
	for(int i = n-1; i >= 0; --i) notwo[i] = notwo[i+1] + (A[i] == 2 ? 0 : 1);
	build(n+1);
	FOR(i, n+1){
		add(i, i, noone[i]+notwo[i]);
	}
	/*FOR(i, n) std::cerr << A[i] << " ";
	std::cerr << "\n";
	FOR(i, n+1) std::cerr << noone[i]+notwo[i] << " ";
	std::cerr << "\n";
	*/
	int best = query(0, n);
	int dd = 0;
	FOR(pos, n){
		if(A[pos] != 0) dd++;
		if(A[pos] != 1) add(0, n, -1);
	//	std::cerr << pos << ": ";
	//	std::cerr << dd << " + " << query(pos+1, n) << "\n";
		best = std::min(best, dd+query(pos+1, n));
	}
	std::cout << best;
	return 0;
}