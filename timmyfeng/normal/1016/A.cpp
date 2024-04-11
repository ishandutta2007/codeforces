#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	ll pre = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ll cur = pre + a;
		cout << cur / m - pre / m << ' ';
		pre = cur;
	}
	cout << '\n';
}