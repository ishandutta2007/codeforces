#include <bits/stdc++.h>
using namespace std;
#define int long long
using ii = array<int, 2>;

const int Z = 2e5, INF = 1e18;

struct SegmentTree {
	const ii ID = {-INF, -1};
	int n; ii *a;
	SegmentTree(int N, ii *A) : n(N), a(new ii[2*n] {}) {
		for(int i = 0; i < n; ++i)
			a[i + n] = A[i];
		for(int i = n; --i; )
			a[i] = max(a[2*i], a[2*i+1]);
	}
	void reset(int i) {
		for(a[i += n] = ID; i /= 2; )
			a[i] = max(a[2*i], a[2*i+1]);
	}
	ii query(int l, int r) {
		ii x = ID;
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if(l & 1) x = max(x, a[l++]);
			if(r & 1) x = max(x, a[--r]);
		}
		return x;
	}
} *sL, *sR;

int n, a, b, p[Z], d[Z];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> a >> b;
		--a, --b;
		for(int i = 0; i < n; ++i)
			cin >> p[i];

		ii seg[n];
		for(int i = 0; i < n; ++i)
			seg[i] = {p[i] + i, i};
		sL = new SegmentTree(n, seg);

		for(int i = 0; i < n; ++i)
			seg[i] = {p[i] - i, i};
		sR = new SegmentTree(n, seg);

		fill(d, d + n, -1);
		queue<int> q;

		auto add = [&](int u, int dist) {
			d[u] = dist;
			q.push(u);
			sL->reset(u);
			sR->reset(u);
		};

		add(a, 0);

		while(!empty(q)) {
			int u = q.front(); q.pop();

			ii v;
			int i = min(n - 1, u + p[u]);
			while((v = sR->query(u, i))[0] >= -u) add(v[1], d[u] + 1);
			i = max((int)0, u - p[u]);

			while((v = sL->query(i, u))[0] >= +u) add(v[1], d[u] + 1);
		}

		cout << d[b] << '\n';
	}
}