#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	int cur = 0;
	int tgt = 0;
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if (i == 1) {
			tgt = a;
		}
		if (i == 1 || a * 2 <= tgt) {
			cur += a;
			ans.push_back(i);
		}
		sum += a;
	}
	
	if (cur * 2 <= sum) {
		cout << 0 << "\n";
	} else {
		cout << ans.size() << "\n";
		for (auto& i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
}