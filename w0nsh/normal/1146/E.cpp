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

struct SumTree{
	int BOTTOM;
	VI t;
	void build(int size){
		BOTTOM = 1;
		while(BOTTOM < size) BOTTOM *= 2;
		t.resize(BOTTOM*2);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return 0;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return query(a, std::min(b, mid), v<<1, lo, mid) +
						query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
	}
	void update(int v, int val){
		v = BOTTOM+v;
		t[v] += val;
		while(v > 1){
			v = v>>1;
			t[v] = t[v<<1] + t[(v<<1)+1];
		}
	}
};

int n, q;

SumTree mn, wc;
int ans[100005];

int SHIFT = 100001;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	FOR(i, n) ans[i] = -1;
	mn.build(200010);
	wc.build(200010);
	VI A(n);
	std::vector<PII> Q;
	FOR(i, n) std::cin >> A[i];
	FOR(i, q){
		char ch;
		int a;
		std::cin >> ch >> a;
		Q.push_back(MP((int)(ch == '>'), a));
	}
	std::reverse(Q.begin(), Q.end());
	std::set<PII, std::greater<PII>> set;
	FOR(i, n) set.insert(MP(std::abs(A[i]), i));
	TRAV(que, Q){
		int x = que.Y;
		if(que.X){
			// auto it = set.lower_bound(MP(-x, -1));
			auto it = set.begin();
			while(it != set.end() && (x > 0 ? (std::abs(x) < it->X) : (std::abs(x) <= it->X))){
				ans[it->Y] = 1 + wc.query(-100000+SHIFT, -it->X-1+SHIFT) + mn.query(it->X+1+SHIFT, 100000+SHIFT);
				ans[it->Y] %= 2;
				// std::cout << "done " << it->Y+1 <<  " at " << que.X << "," << que.Y << std::endl;
				auto next = std::next(it, 1);
				set.erase(it);
				it = next;
			}
			wc.update(x+SHIFT, 1);
		}else{
			auto it = set.begin();
			while(it != set.end() && (x >= 0 ? (std::abs(x) <= it->X) : (std::abs(x) < it->X))){
				ans[it->Y] = 0 + wc.query(-100000+SHIFT, -it->X-1+SHIFT) + mn.query(it->X+1+SHIFT, 100000+SHIFT);
				ans[it->Y] %= 2;
				// std::cout << "done " << it->Y+1 <<  " at " << que.X << "," << que.Y << std::endl;
				auto next = std::next(it, 1);
				set.erase(it);
				it = next;
			}
			mn.update(x+SHIFT, 1);
		}
	}
	FOR(i, n){
		if(A[i] == 0) continue;
		if(ans[i] == -1){
			ans[i] = (A[i] < 0 ? 1 : 0) + wc.query(-100000+SHIFT, -std::abs(A[i])-1+SHIFT) + mn.query(std::abs(A[i])+1+SHIFT, 100000+SHIFT);
			ans[i] %= 2;
		}
		A[i] = std::abs(A[i]);
	}
	FOR(i, n) std::cout << A[i]*(ans[i] == 0 ? 1 : -1) << " ";
	return 0;
}