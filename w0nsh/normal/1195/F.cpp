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


struct SumTree{
	int BOTTOM;
	VI t;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
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
	void add(int v, int val){
		v = BOTTOM+v;
		t[v] += val;
		while(v > 1){
			v = v>>1;
			t[v] = t[v<<1] + t[(v<<1)+1];
		}
	}
};

int sgn(int a){
	if(a < 0) return -1;
	return 1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::vector<PII> > A(n);
	FOR(i, n){
		int k;
		std::cin >> k;
		PII first;
		std::cin >> first.X >> first.Y;
		PII last = first;
		FOR(j, k-1){
			PII cur;
			std::cin >> cur.X >> cur.Y;
			PII ang = MP(cur.X-last.X, cur.Y-last.Y);
			if(ang.Y == 0) ang = MP(sgn(ang.X)*2000002137, 2000002137);
			else if(ang.X == 0) ang = MP(sgn(ang.Y)*2000002137, -2000002137);
			else{
				int gc = std::__gcd(std::abs(ang.X), std::abs(ang.Y));
				ang.X /= gc;
				ang.Y /= gc;
			}
			A[i].push_back(ang);
			last = cur;
		}
		PII ang = MP(first.X-last.X, first.Y-last.Y);
		if(ang.Y == 0) ang = MP(sgn(ang.X)*2000002137, 2000002137);
		else if(ang.X == 0) ang = MP(sgn(ang.Y)*2000002137, -2000002137);
		else{
			int gc = std::__gcd(std::abs(ang.X), std::abs(ang.Y));
			ang.X /= gc;
			ang.Y /= gc;
		}
		A[i].push_back(ang);
		// TRAV(xd, A[i]) std::cout << xd.X << " " << xd.Y << "\n";
	}
	int q;
	std::cin >> q;
	std::vector<PR<PII, int> > que;
	FOR(i, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		que.push_back(MP(MP(a, b), i));
	}
	std::sort(que.begin(), que.end(), [](const PR<PII, int> &a, const PR<PII, int> &b){
		if(a.X == b.X) return a.Y < b.Y;
		if(a.X.Y == b.X.Y) return a.X.X < b.X.X;
		return a.X.Y < b.X.Y;
	});
	VI ans(q);
	SumTree tree;
	tree.build(n);
	std::map<PII, int> last;
	int pos = -1;
	TRAV(pr, que){
		while(pos != pr.X.Y){
			pos++;
			TRAV(xd, A[pos]){
				if(last.count(xd)) tree.add(last[xd], -1);
				last[xd] = pos;
				tree.add(pos, 1);
			}
		}
		ans[pr.Y] = tree.query(pr.X.X, n-1);
	}
	TRAV(i, ans) std::cout << i << "\n";
	return 0;
}