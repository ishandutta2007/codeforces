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

struct Tree{
	int bottom;
	VI t;

	void build(int size){
		bottom = 1;
		while(bottom < size) bottom *= 2;
		t.resize(2*bottom);
	}

	void add(int v, int a){
		v += bottom;
		t[v] += a;
		while(v > 1){
			v>>= 1;
			t[v] += a;
		}
	}

	int query(int a, int b){
		int sum = 0;
		a += bottom;
		b += bottom+1;
		while(a < b){
			if(a & 1) sum += t[a++];
			if(b & 1) sum += t[--b];
			b >>= 1; a >>= 1;
		}
		return sum;
	}

};

int n;
VI A, left, right;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::map<int, int> ile;
	left.resize(n);
	right.resize(n);
	FOR(i, n){
		ile[A[i]]++;
		left[i] = ile[A[i]];
	}
	ile.clear();
	for(int i = n-1; i >= 0; --i){
		ile[A[i]]++;
		right[i] = ile[A[i]];
	}
	Tree tree;
	tree.build(n+5);
	REP(i, 1, n) tree.add(right[i], 1);
	ll ans = 0;
	FOR(i, n-1){
		ans += tree.query(0, left[i]-1);
		tree.add(right[i+1], -1);
	}
	std::cout << ans;
	return 0;
}