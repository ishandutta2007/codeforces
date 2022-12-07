#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0, s = 0;
		while (s < n) 
			s += ++ans;
		if (n + 1 == s) ans++;
		cout << ans << endl;
	}
	return 0;
}