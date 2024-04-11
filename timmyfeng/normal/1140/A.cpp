#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int ans = 0, stop = 0;
	for (int i = 1; i <= n; ++i, ++ans) {
		stop = max(stop, a[i]);
		while (i <= n && stop > i) {
			stop = max(stop, a[++i]);
		}
	}
	cout << ans << '\n';
}