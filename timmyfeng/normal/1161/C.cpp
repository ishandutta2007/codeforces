#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int cnt = 0;
	int mn = *min_element(a.begin(), a.end());
	for (auto i : a) {
		cnt += i == mn;
	}

	cout << (cnt <= n / 2 ? "Alice" : "Bob") << "\n";
}