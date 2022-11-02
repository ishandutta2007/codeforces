#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		int a[n+1] {};
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] += a[i-1];
		}
		int b[n+1] {};
		for(int i = 1; i <= n; ++i) {
			cin >> b[i];
			b[i] += b[i-1];
		}
		set<int> todo;

		for(int i = 0; i <= n; ++i) {
			a[i] -= b[i];
			if(a[i]) todo.insert(i);
		}

		int l[m], r[m];
		bool al[m], ar[m];

		vector<int> bl[n+1], br[n+1];
		queue<int> q;

		for(int i = 0; i < m; ++i) {
			cin >> l[i] >> r[i];
			--l[i];
			al[i] = !a[l[i]];
			ar[i] = !a[r[i]];

			if(!al[i]) {
				bl[l[i]].push_back(i);
			}
			if(!ar[i]) {
				br[r[i]].push_back(i);
			}
			if(al[i] && ar[i]) {
				q.push(i);
			}
		}

		while(!empty(q)) {
			int i = q.front(); q.pop();

			while(1) {
				auto f = todo.lower_bound(l[i]);
				if(f == todo.end() || *f > r[i]) break;
				int j = *f;

				for(int k : bl[j]) {
					al[k] = 1;
					if(al[k] && ar[k]) q.push(k);
				}
				for(int k : br[j]) {
					ar[k] = 1;
					if(al[k] && ar[k]) q.push(k);
				}

				todo.erase(f);
			}
		}

		cout << (empty(todo) ? "YES" : "NO") << '\n';
	}
}