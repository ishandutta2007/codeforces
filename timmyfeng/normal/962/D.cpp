#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	map<ll, vector<int>> mp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	set<ll> in_pq;
	for (auto& i : mp) {
		if (i.second.size() >= 2u) {
			pq.push(i.first);
			in_pq.insert(i.first);
		}
	}

	while (!pq.empty()) {
		ll u = pq.top();
		pq.pop();

		vector<int> pos = mp[u];
		sort(pos.begin(), pos.end());
		for (int i = 0; i + 1 < (int)pos.size(); i += 2) {
			a[pos[i]] = 0;
			a[pos[i + 1]] = u * 2;
			mp[u * 2].push_back(pos[i + 1]);
		}

		if (mp[u * 2].size() >= 2u && !in_pq.count(u * 2)) {
			pq.push(u * 2);
			in_pq.insert(u * 2);
		}
	}

	cout << n - count(a.begin(), a.end(), 0) << '\n';
	for (auto i : a) {
		if (i) {
			cout << i << ' ' ;
		}
	}
	cout << '\n';
}