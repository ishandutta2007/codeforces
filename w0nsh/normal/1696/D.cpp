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

struct MaxTree{
	int BOTTOM;
	std::vector<PII> t;
	void build(VI A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t = std::vector<PII>(BOTTOM * 2, MP(-INF, -1));
		FOR(i, SZ(A)) t[i+BOTTOM] = MP(A[i], i);
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::max(t[i<<1], t[(i<<1)+1]);
	}

	PII query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		PII ret = MP(-INF, -1);
		while(a < b){
			if(a&1) ret = std::max(ret, t[a++]);
			if(b&1) ret = std::max(ret, t[--b]);
			a>>=1;b>>=1;
		}
		return ret;
	}
};


struct MinTree{
	int BOTTOM;
	std::vector<PII> t;
	void build(VI A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t = std::vector<PII>(BOTTOM * 2, MP(INF, -1));
		FOR(i, SZ(A)) t[i+BOTTOM] = MP(A[i], i);
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::min(t[i<<1], t[(i<<1)+1]);
	}

	PII query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		PII ret = MP(INF, -1);
		while(a < b){
			if(a&1) ret = std::min(ret, t[a++]);
			if(b&1) ret = std::min(ret, t[--b]);
			a>>=1;b>>=1;
		}
		return ret;
	}
};

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<PII> stos;
	VI wk(n, n);
	for(int i = n-1; i >= 0; --i){
		while(SZ(stos) && stos.back().X < A[i]){
			stos.pop_back();
		}
		if(!stos.empty()){
			wk[i] = stos.back().Y;
		}
		stos.push_back(MP(A[i], i));
	}

	stos.clear();
	VI mn(n, n);
	for(int i = n-1; i >= 0; --i){
		while(SZ(stos) && stos.back().X > A[i]){
			stos.pop_back();
		}
		if(!stos.empty()){
			mn[i] = stos.back().Y;
		}
		stos.push_back(MP(A[i], i));
	}

	// FOR(i, n) std::cout << wk[i] << " ";
	// std::cout << "\n";
	// FOR(i, n) std::cout << mn[i] << " ";
	// std::cout << "\n";

	MaxTree maxt;
	maxt.build(A);
	MinTree mint;
	mint.build(A);

	VI dist(n, INF);
	dist[0] = 0;
	FOR(i, n-1){
		int xd = std::max(wk[i], mn[i]);
		dist[i+1] = std::min(dist[i+1], dist[i] + 1);

		xd--;
		if(A[i] > A[i+1]){
			auto heh = mint.query(i+1, xd);
			assert(heh.Y != -1);
			dist[heh.Y] = std::min(dist[heh.Y], dist[i] + 1);
		}else{
			auto heh = maxt.query(i+1, xd);
			assert(heh.Y != -1);
			dist[heh.Y] = std::min(dist[heh.Y], dist[i] + 1);
		}
	}
	std::cout << dist[n-1] << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}