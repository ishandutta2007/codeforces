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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
 
//X.find_by_order(k); - zwraca iterator na k-ty element (numeracja od zerowego)
//X.order_of_key(k); - zwraca liczb elementw ostro mniejszych ni k

struct Tree{
	int BOTTOM;
	std::vector<ll> t, u;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
	}
	void upd(int v, int lo, int hi){
		t[v] += u[v]*(hi-lo+1);
		if(v < BOTTOM){
			u[v<<1] += u[v];
			u[(v<<1)+1] += u[v];
		}
		u[v] = 0;
	}
	ll query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2)hi=BOTTOM-1;
		upd(v, lo, hi);
		if(a>b) return 0;
		if(a==lo&&b==hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return query(a, std::min(b,mid), v<<1, lo, mid)
			+ query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
	}
	void add(int a, int b, int w, int v=1, int lo=0, int hi=-2){
		if(hi==-2)hi=BOTTOM-1;
		upd(v, lo, hi);
		if(a>b) return;
		if(a==lo&&b==hi){
			u[v] += w;
			upd(v, lo, hi);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b,mid), w, v<<1, lo, mid);
		add(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		t[v] = t[(v<<1)+1] + t[v<<1];
	}
};

int ile(ordered_set<int> &set, int a, int b){
	return set.order_of_key(b+1)-set.order_of_key(a);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	VI R(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i]--;
	FOR(i, n) R[A[i]] = i;
	std::vector<ll> inv(n);
	Tree tree;
	tree.build(n);
	FOR(i, n){
		inv[i] = tree.query(R[i], R[i]);
		tree.add(0, R[i], 1);
	}
	REP(i, 1, n) inv[i] += inv[i-1];
	ordered_set<int> set;
	set.insert(R[0]);
	Tree tr;
	tr.build(n);
	ll odejm = 0;
	REP(i, 1, n){
		int last = *set.find_by_order(SZ(set)/2);
		odejm += tr.query(R[i], R[i]);
		set.insert(R[i]);
		int now = *set.find_by_order(SZ(set)/2);
		if(SZ(set)%2 == 0){
			// do starej
			int a = last;
			int b = R[i];
			if(a > b) std::swap(a, b);
			tr.add(a, b, 1);
			odejm += ile(set, a, b);
		}else{
			int a = now;
			int b = R[i];
			if(a > b) std::swap(a, b);
			tr.add(a, b, 1);
			odejm += ile(set, a, b);
			// do nowej
		}
		inv[i] += tr.query(0, n-1)-odejm;
	}
	TRAV(i, inv) std::cout << i << " ";
	std::cout << "\n";
	return 0;
}