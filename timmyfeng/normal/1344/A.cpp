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
		for (auto& i : a) {
			cin >> i;
			i = (i % n);
			if (i < 0) {
				i += n;
			}
		}
		vector<bool> cnt(n);
		for (int i = 0; i < n; ++i) {
			cnt[(a[i] + i) % n] = true;
		}
		cout << (count(cnt.begin(), cnt.end(), false) ? "NO" : "YES") << '\n';
	}
}