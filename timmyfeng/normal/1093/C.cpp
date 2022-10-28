#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> b(n / 2);
	for (auto& i : b) {
		cin >> i;
	}
	vector<ll> a(n);
	for (int i = 0; i < n / 2; ++i) {
		if (i) {
			a[i] = max(a[i - 1], b[i] - a[n - i]);
		}
		a[n - 1 - i] = b[i] - a[i];
	}
	for (auto i : a) {
		cout << i << ' ';
	}
	cout << '\n';
}