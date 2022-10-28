#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int b, k;
	cin >> b >> k;

	vector<int> a(k);
	for (auto& i : a) {
		cin >> i;
	}

	int ans = 0;
	if (b % 2) {
		for (auto i : a) {
			ans ^= i % 2;
		}
	} else {
		ans = a.back() % 2;
	}

	cout << (ans ? "odd" : "even") << "\n";
}