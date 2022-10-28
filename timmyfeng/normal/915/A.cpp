#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (k % a == 0) {
			ans = min(ans, k / a);
		}
	}
	cout << ans << '\n';
}