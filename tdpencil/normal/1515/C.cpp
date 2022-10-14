#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, m, k; cin >> n >> m >> k;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		
		for(int i = 0; i < m; i++) pq.push({0, i});
		vector<int> colors(n, -1);
		
		for(int i = 0; i < n; i++) {
			pair<int, int> x = pq.top();
			pq.pop();
			colors[i] = x.second;
			x.first += a[i];
			pq.push(x);
		}
		
		vector<int> towers(m);
		
		while(pq.size()) {
			pair<int, int> x = pq.top();
			pq.pop();
			towers[x.second] = x.first;
		}
		
		
		if(false) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for(int i = 0; i < n; ++i) {
				cout << colors[i] + 1 << " ";
			}
			cout << "\n";
		}
	}
	
}