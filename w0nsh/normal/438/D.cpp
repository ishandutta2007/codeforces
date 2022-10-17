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

int n, m;
VI A;

struct MaxTree{
	int BOTTOM;
	VI t;
	void get(int &a, int b, int c){
		if(b == -1) a = c;
		else if(c == -1) a = b;
		else if(A[b] < A[c]) a = c;
		else a = b;
	}
	void build(){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *=2;
		t.resize(BOTTOM*2, -1);
		FOR(i, SZ(A)) t[i+BOTTOM] = i;
		for(int i = BOTTOM-1; i >= 1; --i){
			get(t[i], t[i<<1], t[(i<<1)+1]);
		}
	}
	void update(int v){
		v += BOTTOM;
		while(v > 1){
			v >>= 1;
			get(t[v], t[v<<1], t[(v<<1)+1]);
		}
	}
	int query(int a, int b){
		int max = a;
		a += BOTTOM;
		b += BOTTOM+1;
		while(a<b){
			if(a&1){
				if(t[a] != -1 && A[t[a]] > A[max]) max = t[a];
				a++;
			}
			if(b&1){
				--b;
				if(t[b] != -1 && A[t[b]] > A[max]) max = t[b];
			}
			a>>=1;b>>=1;
		}
		return max;
	}
};

struct SumTree{
	int BOTTOM;
	std::vector<ll> t;
	void build(){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		FOR(i, SZ(A)) t[i+BOTTOM] = A[i];
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = t[i<<1]+t[(i<<1)+1];
		}
	}
	void add(int v, int x){
		v += BOTTOM;
		while(v >= 1){
			t[v] += x;
			v >>= 1;
		}
	}
	ll query(int a, int b){
		ll ret = 0;
		a += BOTTOM;
		b += BOTTOM+1;
		while(a<b){
			if(a&1) ret += t[a++];
			if(b&1) ret += t[--b];
			a>>=1;b>>=1;
		}
		return ret;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	MaxTree mtree;
	mtree.build();
	SumTree stree;
	stree.build();
	FOR(_, m){
		int type;
		std::cin >> type;
		if(type == 1){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			std::cout << stree.query(a, b) << "\n";
		}else if(type == 2){
			int a, b, c;
			std::cin >> a >> b >> c;
			a--;b--;
			while(true){
				int mx = mtree.query(a, b);
				if(A[mx] < c) break;
				int old = A[mx];
				A[mx] %= c;
				mtree.update(mx);
				stree.add(mx, A[mx]-old);
			}
		}else{
			int a, b;
			std::cin >> a >> b;
			a--;
			int old = A[a];
			A[a] = b;
			mtree.update(a);
			stree.add(a, A[a]-old);
		}
	}
	return 0;
}