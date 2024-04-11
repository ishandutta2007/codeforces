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
		vector<int> a(n), b(n);
		for (auto& i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end());
		for (auto i : a) {
			cout << i << ' ';
		}
		cout << '\n';
		for (auto& i : b) {
			cin >> i;
		}
		sort(b.begin(), b.end());
		for (auto i : b) {
			cout << i << ' ' ;
		}
		cout << '\n';
	}
}