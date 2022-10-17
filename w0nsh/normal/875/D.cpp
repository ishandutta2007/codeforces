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

const int LOG = 30;
const int INF = 1000000666;

struct Tree{
	int BOTTOM;
	std::vector<PII> t;

	void build(VI A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t.resize(BOTTOM*2, MP(-INF, 1));
		FOR(i, SZ(A)) t[i+BOTTOM] = MP(A[i], -i);
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::max(t[i<<1], t[(i<<1)+1]);
	}

	PII query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		PII ret = MP(-INF, 1);
		while(a < b){
			if(a&1) ret = std::max(ret, t[a++]);
			if(b&1) ret = std::max(ret, t[--b]);
			a>>=1;b>>=1;
		}
		ret.Y *= -1;
		return ret;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	std::vector<VI> pos(LOG);
	FOR(l, LOG){
		FOR(i, n) if(A[i] & (1<<l)) pos[l].push_back(i);
		std::reverse(pos[l].begin(), pos[l].end());
	}

	Tree tree;
	tree.build(A);

	ll ans = 0;

	FOR(i, n){
		std::vector<PII> gdzie;
		FOR(l, LOG){
			if(SZ(pos[l]) > 0) gdzie.push_back(MP(pos[l].back(), l));
			if(SZ(pos[l]) > 0 && pos[l].back() == i) pos[l].pop_back();
		}

		std::sort(gdzie.begin(), gdzie.end());
		gdzie.push_back(MP(n, -1));
		int p = 0;
		int mam = 0;
		while(gdzie[p].X < n){
			assert(gdzie[p].Y != -1);

			int x = gdzie[p].X;
			mam |= (1<<gdzie[p].Y);
			p++;
			while(p < SZ(gdzie) && gdzie[p].X == x){
				mam |= (1<<gdzie[p].Y);
				p++;
			}

			int from = x;
			int to = gdzie[p].X-1;

			if(from <= to){
				auto mx = tree.query(from, to);
				if(mx.X == mam) to = mx.Y-1;
				ans += to-from+1;
			}
		}
	}

	std::cout << ans << "\n";
	

	return 0;
}