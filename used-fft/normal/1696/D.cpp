#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 2e9;
using ii = array<int, 2>;

ii ID = {INF, -1};

struct ST {
	int n = 1, rev = 0; vector<ii> a;
	void init(int N, int REV) {
		a.assign(2 * (n = N), ID);
		rev = REV;
	}
	void update(int i, ii v) {
		if(rev) v[0] = -v[0];
		for(a[i+=n]=v; i/=2; ) a[i] = min(a[2*i], a[2*i+1]);
	}
	ii query(int l, int r) {
		ii x = ID;
		for(l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if(l & 1) x = min(x, a[l++]);
			if(r & 1) x = min(x, a[--r]);
		}
		if(rev) x[0] = -x[0];
		return x;
	}
};

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i;


		int l[2][n], r[2][n];

		for(int k : {0, 1}) {
			vector<int> s;

			for(int i = 0; i < n; ++i) {
				while(!empty(s) && a[s.back()] > a[i])
					s.pop_back();
				l[k][i] = empty(s) ? -1 : s.back();
				s.push_back(i);
			}
			s.clear();

			for(int i = n; i--; ) {
				while(!empty(s) && a[s.back()] > a[i])
					s.pop_back();
				r[k][i] = empty(s) ? n : s.back();
				s.push_back(i);
			}

			for(int &i : a) i = -i;
		}

		ST ls[2], rs[2];

		for(int k : {0, 1}) {
			ls[k].init(n, 0);
			rs[k].init(n, 1);

			for(int i = 0; i < n; ++i) {
				ls[k].update(i, {l[k][i], i});
				rs[k].update(i, {r[k][i], i});
			}
		}

		queue<int> q;
		int d[n];
		fill(d, d + n, INF);
		d[0] = 0;

		auto add = [&](int u) {
			q.push(u);
			for(int k : {0, 1}) {
				ls[k].update(u, {n, -1});
				rs[k].update(u, {-1, -1});
			}
		};
		add(0);

		while(!empty(q)) {
			int u = q.front(); q.pop();

			for(int k : {0, 1}) {
				int j = r[k][u] - 1;

				ii v;
				while((v = ls[!k].query(u, j))[0] < u) {
					d[v[1]] = d[u] + 1;
					add(v[1]);
				}

				j = l[k][u] + 1;
				while((v = rs[!k].query(j, u))[0] > u) {
					d[v[1]] = d[u] + 1;
					add(v[1]);
				}
			}
		}

		cout << d[n-1] << '\n';
	}
}