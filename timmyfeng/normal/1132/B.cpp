#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	for (auto& i : a) {
		cin >> i;
		sum += i;
	}
	sort(a.begin(), a.end());
	
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int q;
		cin >> q;
		cout << sum - a[n - q] << '\n';
	}
}