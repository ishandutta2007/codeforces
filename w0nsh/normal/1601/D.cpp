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

constexpr int INF = 1000000666;

struct Tree{
	int BOTTOM;
	VI t, u;

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = VI(BOTTOM*2);
		u = VI(BOTTOM*2);
	}

	void upd(int v){
		t[v] += u[v];
		if(v < BOTTOM){
			u[v<<1] += u[v];
			u[(v<<1)+1] += u[v];
		}
		u[v] = 0;
	}

	void add(int a, int b, int val, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] += val;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), val, v<<1, lo, mid);
		add(std::max(a, mid+1), b, val, (v<<1)+1, mid+1, hi);
		t[v] = std::max(t[v<<1], t[(v<<1)+1]);
	}

	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi= BOTTOM-1;
		upd(v);
		if(a>b) return 0;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return std::max(query(a, std::min(b, mid), v<<1, lo, mid),
			query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, d;
	std::cin >> n >> d;
	std::vector<PII> A;
	int ans = 0;
	FOR(i, n){
		int s, a;
		std::cin >> s >> a;
		if(s < d){
			continue;
		}
		if(a <= d){
			ans++;
			continue;
		}
		A.push_back(MP(a, s));
	}
	n = SZ(A);
	A.push_back(MP(d, 0));
	std::sort(A.begin(), A.end());

	Tree tree;
	tree.build(n+1);

	std::priority_queue<PII, std::vector<PII>, std::greater<PII>> que;

	int best = 0;

	REP(i, 1, n+1){
		auto[a, s] = A[i];

		while(!que.empty() && que.top().X < a){
			int v = que.top().Y;
			que.pop();
			tree.add(0, v-1, -1);
		}

		int from = 0;
		int upto = std::lower_bound(A.begin(), A.end(), MP(s+1, -5)) - A.begin();
		upto--;
		assert(upto >= 0);

		int my = tree.query(from, upto) + 1;
		best = std::max(best, my);
		tree.add(i, i, my);

		tree.add(0, i-1, 1);
		que.push(MP(s, i));
	}

	std::cout << best+ans << "\n";

	return 0;
}