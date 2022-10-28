#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		int inc = 0;
		while (a[inc] >= inc) {
			++inc;
		}
		int dec = 0;
		while (a[n - 1 - dec] >= dec) {
			++dec;
		}
		cout << (inc + dec > n ? "Yes\n" : "No\n");
	}
}