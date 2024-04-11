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

struct MinTree{
	int BOTTOM;
	VI t, vec;
	inline int left(int a){
		return a<<1;
	}
	inline int right(int a){
		return (a<<1)+1;
	}
	inline int parent(int a){
		return a>>1;
	}
	void prop(int v){
		if(v >= BOTTOM) return;
		prop(left(v));
		prop(right(v));
		if(vec[t[left(v)]] < vec[t[right(v)]]) t[v] = t[left(v)];
		else t[v] = t[right(v)];
	}
	void build(VI vc){
		int size = SZ(vc);
		vec = vc;
		BOTTOM = 1;
		while(BOTTOM < size){
			BOTTOM *= 2;
		}
		while(SZ(vec) < BOTTOM) vec.push_back(INF);
		t.resize(BOTTOM*2);
		FOR(i, BOTTOM) t[i+BOTTOM] = i;
		prop(1);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return -1;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		int l = query(a, std::min(b, mid), left(v), lo, mid);
		int r = query(std::max(a, mid+1), b, right(v), mid+1, hi);
		if(l == -1) return r;
		if(r == -1) return l;
		if(vec[l] < vec[r]) return l;
		return r;
	}
	void update(int v, int val){
		vec[v] = val;
		v += BOTTOM;
		while(v > 1){
			v = parent(v);
			if(vec[t[left(v)]] < vec[t[right(v)]]) t[v] = t[left(v)];
			else t[v] = t[right(v)];
		}
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i]; 
	FOR(i, n) A[i] = n-A[i];
	MinTree tree;
	tree.build(A);
	VI ans(n);
	int done = 0;
	int kto = 0;
	VI right(n);
	VI left(n);
	REP(i, 1, n) left[i] = i-1;
	FOR(i, n-1) right[i] = i+1;
	right[n-1] = -1;
	left[0] = -1;
	while(done < n){
		int min = tree.query(0, n-1);
		tree.update(min, INF);
		ans[min] = kto;
		done++;
		int rp = min;
		FOR(i, k){
			rp = right[rp];
			if(rp == -1) break;
			tree.update(rp, INF);
			done++;
			ans[rp] = kto;
		}
		int lp = min;
		FOR(i, k){
			lp = left[lp];
			if(lp == -1) break;
			tree.update(lp, INF);
			done++;
			ans[lp] = kto;
		}
		if(lp != -1){
			if(left[lp] != -1){
				right[left[lp]] = (rp == -1 ? -1 : right[rp]);
			}
		}
		if(rp != -1){
			if(right[rp] != -1){
				left[right[rp]] = (lp == -1 ? -1 : left[lp]);
			}
		}
		kto = 1-kto;
	}
	FOR(i, n) std::cout << ans[i]+1;
	return 0;
}