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
	void build(const VI &A){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM <<= 1;
		t.resize(BOTTOM<<1);
		FOR(i, SZ(A)) t[BOTTOM+i] = A[i];
	}
	int query(int v){
		int sum = 0;
		v += BOTTOM;
		while(v > 0){
			sum += t[v];
			v >>= 1;
		}
		return sum;
	}
	void add(int a, int b, int v){
		a += BOTTOM;
		b += BOTTOM+1;
		while(a < b){
			if(a&1) t[a++] += v;
			if(b&1) t[--b] += v;
			a >>= 1; b >>= 1;
		}
	}
};

struct KthTree{
	int BOTTOM;
	VI t;
	void build(int size){
		BOTTOM = 1;
		while(BOTTOM < size) BOTTOM <<= 1;
		t.resize(BOTTOM*2);
		FOR(i, size) t[BOTTOM+i] = 1;
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = t[i<<1]+t[(i<<1)+1];
		}
	}
	void rem(int a){
		a += BOTTOM;
		while(a > 0){
			t[a]--;
			a >>= 1;
		}
	}
	int kth(int k){
		int v = 1;
		while(v < BOTTOM){
			if(t[v<<1] <= k) k -= t[v<<1], v = (v<<1)+1;
			else v <<= 1;
		}
		return v-BOTTOM;
	}
};


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n), B(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) std::cin >> B[i];
	VI xd;
	FOR(i, n) xd.push_back(i);
	SumTree fs, sc;
	fs.build(xd);
	sc.build(xd);
	VI ret(n);
	VI Af(n), Bf(n);
	FOR(i, n){
		Af[i] = fs.query(A[i]);
		Bf[i] = sc.query(B[i]);
		fs.add(A[i], n-1, -1);
		sc.add(B[i], n-1, -1);
	}
	int carry = 0;
	std::reverse(Af.begin(), Af.end());
	std::reverse(Bf.begin(), Bf.end());
	FOR(i, n){
		ret[i] = (Af[i]+Bf[i]+carry)%(i+1);
		carry = (Af[i]+Bf[i]+carry)/(i+1);
	}
	std::reverse(ret.begin(), ret.end());
	KthTree tree;
	tree.build(n);
	VI ans(n);
	FOR(i, n){
		ans[i] = tree.kth(ret[i]);
		tree.rem(ans[i]);
	}
	TRAV(i, ans) std::cout << i << " ";
	std::cout << "\n";
	return 0;
}