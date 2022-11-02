#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i, --i;

		vector<int> h[n];
		for(int i = 0; i < n; ++i) {
			h[a[i]].push_back(i);
		}

		priority_queue<array<int, 2>> pq;
		for(int i = 0; i < n; ++i) {
			if(!empty(h[i])) pq.push({int(size(h[i])), i});
		}

		while(pq.size() > 1) {
			auto [cI, i] = pq.top(); pq.pop();
			auto [cJ, j] = pq.top(); pq.pop();

			int u = h[i].back(); h[i].pop_back();
			int v = h[j].back();
			swap(a[u], a[v]);


			for(int k : {i, j})
				if(!empty(h[k])) pq.push({int(size(h[k])), k});
		}

		for(int i : a) cout << i+1 << ' ';
		cout << '\n';
	}
}