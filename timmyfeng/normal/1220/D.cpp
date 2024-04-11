#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	set<long long> a;
	map<long long, int> mp;
	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		a.insert(x);
		++mp[x & -x];
	}

	int best = 0;
	long long power = 0;
	for (auto& i : mp) {
		if (i.second > best) {
			best = i.second;
			power = i.first;
		}
	}

	vector<long long> ans;
	for (auto& i : a) {
		if ((i & -i) != power) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << "\n";
	for (auto& i : ans) {
		cout << i << " " ;
	}
	cout << "\n";
}