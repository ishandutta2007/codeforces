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

struct Tree{
	std::vector<PII> t;
	VI A;
	int BOTTOM;

	int better(int a, int b){
		if(a == -1) return b;
		if(b == -1) return a;
		return (A[a] > A[b] ? a : b);
	}

	PII merge(PII a, PII b){
		if(better(a.X, b.X) == a.X){
			return MP(a.X, better(a.Y, b.X));
		}else{
			return MP(b.X, better(b.Y, a.X));
		}
	}

	void build(VI ar){
		A = std::move(ar);
		BOTTOM = 1;
		while(BOTTOM < SZ(A)){
			BOTTOM *= 2;
		}
		t = std::vector<PII>(BOTTOM*2, MP(-1, -1));
		FOR(i, SZ(A)) t[i+BOTTOM] = MP(i, -1);
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = merge(t[i<<1], t[(i<<1)+1]);
		}
	}

	PII query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		PII ret = MP(-1, -1);
		while(a < b){
			if(a & 1) ret = merge(ret, t[a++]);
			if(b & 1) ret = merge(ret, t[--b]);
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
	std::vector<PR<PII, PII>> prz;
	std::vector<PII> que;
	FOR(i, q){
		int t;
		std::cin >> t;
		if(t == 0){
			int l, r, x;
			std::cin >> l >> r >> x;
			l--;r--;
			prz.push_back(MP(MP(l, r), MP(x, i)));
		}else{
			int j;
			std::cin >> j;
			j--;
			que.push_back(MP(j, i));
		}
	}

	std::vector<PII> ev;
	TRAV(pr, prz){
		if(pr.Y.X == 0){
			ev.push_back(MP(pr.X.X, pr.Y.Y+1));
			ev.push_back(MP(pr.X.Y+1, -pr.Y.Y-1));
		}
	}

	std::sort(ev.begin(), ev.end());
	auto it = ev.begin();
	std::multiset<int> set;
	constexpr int INF = 1000000666;
	VI prw(n, INF);
	FOR(i, n){
		while(it != ev.end() && it->X == i){
			int y = it->Y;
			if(y < 0){
				y = -y;
				y--;
				set.erase(set.find(y));
			}else{
				y--;
				set.insert(y);
			}
			++it;
		}

		if(SZ(set)) prw[i] = *set.begin();
	}

	Tree tree;
	tree.build(prw);

	// std::cout << "prw ";
	// TRAV(i, prw) std::cout << i << " ";
	// std::cout << std::endl;


	VI known(n, INF);
	TRAV(pr, prz){
		if(pr.Y.X == 1){
			// std::cout << "pytam " << pr.X.X << " " << pr.X.Y << std::endl;
			PII xd = tree.query(pr.X.X, pr.X.Y);
			// std::cout << "mam " << xd.X << " " << xd.Y << std::endl;
			assert(prw[xd.X] == INF);
			if(pr.X.X == pr.X.Y){
				assert(xd.X == pr.X.X);
				known[xd.X] = std::min(known[xd.X], pr.Y.Y);
			}else if(prw[xd.Y] < INF){
				known[xd.X] = std::min(known[xd.X], std::max(prw[xd.Y], pr.Y.Y));
			}
		}
	}

	TRAV(i, que){
		if(prw[i.X] < i.Y){
			std::cout << "NO\n";
		}else if(known[i.X] < i.Y){
			std::cout << "YES\n";
		}else{
			std::cout << "N/A\n";
		}
	}

	return 0;
}