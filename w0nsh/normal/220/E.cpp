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


int compress(VI &A){
	std::map<int, int> map;
	std::set<int> set;
	TRAV(i, A) set.insert(i);
	int fre = 0;
	TRAV(i, set) map[i] = fre++;
	TRAV(i, A) i = map[i];
	return fre;
}

struct Tree{
	int BOTTOM;
	VI t;
	void build(int size){
		BOTTOM = 1;
		while(BOTTOM < size) BOTTOM <<= 1;
		t.resize(BOTTOM<<1);
	}
	int query(int a, int b){
		int ret = 0;
		a += BOTTOM;
		b += BOTTOM+1;
		while(a < b){
			if(a&1) ret += t[a++];
			if(b&1) ret += t[--b];
			a >>= 1; b>>= 1;
		}
		return ret;
	}
	void add(int v, int w){
		v += BOTTOM;
		while(v > 0){
			t[v] += w;
			v >>= 1;
		}
	}
};

int n;
ll k;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	int ile = compress(A);
	Tree tree;
	tree.build(ile);
	int left = 0;
	int right = 1;
	ll ans = 1ll*n*(n-1)/2;
	ll invs = 0;
	Tree lt, rt;
	lt.build(ile);
	rt.build(ile);
	lt.add(A[0], 1);
	REP(i, 1, n){
		if(A[i] < A[0]) invs++;
		invs += rt.query(A[i]+1, ile-1);
		rt.add(A[i], 1);
	}
	while(right < n){
		while(left < right-1 && invs <= k){
			left++;
			invs += lt.query(A[left]+1, ile-1);
			invs += rt.query(0, A[left]-1);
			lt.add(A[left], 1);
		}
		if(right - left == 1){
			if(invs > k) ans -= 1;
		}else{
			ans -= right-left;
		}
		invs -= lt.query(A[right]+1, ile-1);
		invs -= rt.query(0, A[right]-1);
		rt.add(A[right], -1);
		right++;
	}
	std::cout << ans << "\n";
	return 0;
}