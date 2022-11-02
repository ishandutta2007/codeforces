#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int Z = 2e5;

struct UFDS{
	vector<int> e;
	int c;
	int operator()(int u){
		return e[u] < 0 ? u : e[u] = (*this)(e[u]);
	}
	void operator()(int u, int v){
		u = (*this)(u), v = (*this)(v);
		if(u == v) return;
		--c;
		if(e[u] > e[v]) swap(u, v);
		e[u] += e[v], e[v] = u;
	}
	UFDS(int n){ e.assign(c=n, -1); }
};

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		array<int, 3> e[m];
		for(auto &i : e) {
			cin >> i[1] >> i[2] >> i[0];
			--i[1], --i[2];
		}

		sort(e, e+m);

		int ex = 0;

		for(int b=1LL<<33; b/=2LL; ) {
			int x = ex | b;

			UFDS g(n);
			for(auto &[w, u, v] : e) {
				if(!(w & x)) g(u, v);
			}

			if(g.c < 2) ex |= b;
		}

		ex = ((1LL<<33)-1)^ex;

		cout << ex << '\n';
	}
}