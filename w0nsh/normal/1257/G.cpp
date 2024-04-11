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

const int MOD = 998244353;
int R;

int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e >>= 1;
	}
	return ret;
}

void findr(){
	R = -1;
	REP(i, 2, 1000){
		if(modpow(i, (MOD-1)/2) != 1 &&
			modpow(i, (MOD-1)/7) != 1 &&
			modpow(i, (MOD-1)/17) != 1){
				R = i;
				break;
			}
	}
	assert(R!=-1);
	//std::cerr << "R=" << R << std::endl;
}

void ntt(VI &a, bool inv=false){
	int n = SZ(a);
	// bit reorder
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) std::swap(a[i], a[j]);
	}
	for(int sz = 2; sz <= n; sz *= 2){
		int c = (MOD-1)/sz;
		int step = modpow(R, c);
		if(inv) step = modpow(step, MOD-2);
		for(int i = 0; i < n; i += sz){
			int w = 1;
			for(int j = 0; j < sz/2; ++j){
				int u = a[i+j];
				int v = (1ll*a[i+j+sz/2]*w)%MOD;
				a[i+j] = u + v < MOD ? u + v : u + v - MOD;
				a[i+j+sz/2] = u - v >= 0 ? u - v : u - v + MOD;
				w = (1ll*w*step)%MOD;
			}
		}
	}
	if(inv){
		int odw = modpow(n, MOD-2);
		TRAV(i, a) i = (1ll*i*odw)%MOD;
	}
}

struct Poly{
	VI c;
	Poly(){}
	Poly(VI v) : c(v) {}
	int size(){
		return SZ(c);
	}
	void operator *=(Poly b){
		assert(b.size() == this->size());
		int n = b.size();
		FOR(i, n) b.c.push_back(0), this->c.push_back(0);
		ntt(this->c);
		ntt(b.c);
		FOR(i, SZ(b.c)) this->c[i] = (1ll*this->c[i]*b.c[i])%MOD;
		ntt(this->c, true);
	}
};

std::ostream &operator <<(std::ostream &s, Poly &p){
	s << "[";
	FOR(i, SZ(p.c)){
		if(i != 0) s << " ";
		s << p.c[i];
	}
	s << "]";
	return s;
}

int n;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	findr();
	std::cin >> n;
	std::map<int, int> map;
	FOR(i, n){
		int a;
		std::cin >> a;
		map[a]++;
	}
	std::vector<Poly> A;
	TRAV(pr, map){
		Poly pol;
		int siz = pr.Y+1;
		while(__builtin_popcount(siz) != 1) siz++;
		pol.c.resize(siz);
		FOR(i, pr.Y+1) pol.c[i] = 1;
		A.push_back(pol);
	}
	auto comp = [&](int a, int b){
		return A[a].size() > A[b].size();
	};
	std::priority_queue<int, std::vector<int>, decltype(comp)> que(comp);
	FOR(i, SZ(A)) que.push(i);
	while(SZ(que) > 1){
	int a = que.top();
		que.pop();
		int b = que.top();
		que.pop();
		if(A[a].size() < A[b].size()) A[a].c.resize(A[b].size(), 0);
		A[a] *= A[b];
		que.push(a);
	}
	std::cout << A[que.top()].c[n/2] << "\n";
	return 0;
}