#include <bits/stdc++.h>
using namespace std;
#define int long long

// {answer, a[L], max valid prefix, a[R], ..., length}
// {0,      1,    2,                3,    4,   5}

template<class T> struct SegmentTree{
	T comb(T &x, T &y){
		if(x == ID) return y;
		if(y == ID) return x;
		int res = x[0] + y[0];
		// cout << x[5] << ' ' << y[5] << '\n';

		int lv = x[2];
		int rv = y[4];

		if(x[3] <= y[1]){
			res += x[4] * y[2];

			if(x[2] == x[5]) lv += y[2];
			if(y[4] == y[5]) rv += x[4];
		}

		return {res, x[1], lv, y[3], rv, x[5] + y[5]};
	}
	int n = 1, i; vector<T> a; const T ID = {-1, -1, 1, -1, 1, 1};
	SegmentTree(int N){ while(n<N) a.resize(2*(n+=n), ID); }
	SegmentTree& operator[](int j){ i=j+n; return *this; }
	void operator=(int v){
		a[i] = {1, v, 1, v, 1, 1};
		while(i/=2) a[i] = comb(a[2*i], a[2*i+1]); }
	int operator()(int l, int r){
		T lx = ID, rx = ID;
		for(l+=n, r+=n+1; l<r; l/=2, r/=2){
			if(l & 1) lx = comb(lx, a[l++]);
			if(r & 1) rx = comb(a[--r], rx);
		}	
		return comb(lx, rx)[0];
	}
	operator T(){ return a[i]; }
};

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;

	SegmentTree<array<int, 6>> st(n+1);

	for(int i=1; i<=n; ++i){
		int v; cin >> v;
		st[i] = v;
	}

	while(q--){
		int t, x, y; cin >> t >> x >> y;
		if(t < 2) st[x] = y;
		else cout << st(x, y) << '\n';
	}
}