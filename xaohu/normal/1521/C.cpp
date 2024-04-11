#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++) 

using namespace std;

int t, n, ans[1 << 20];

int ask(int q, int i, int j, int e) {
	cout << "? " << q << " " << i << " " << j << " " << e << endl;
	cin >> i;
	return i;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int one = 0;
		vector<int> can;
		
		for (int i = 1; i <= n; i += 2) {
			if (i == n) {
				can.push_back(i);
			}
			else {
				int f = ask(2, i, i + 1, 1);
				if (f == 1)
					one = i;
				if (f == 2) {
					can.push_back(i);
					can.push_back(i + 1);
				}
			}
		}
		
		for (auto x : can)
			for (auto y : can) {
				if (one || x == y) continue;
				if (ask(2, x, y, 1) == 1) {
					one = x;
				}
			}
		
		
		rep(i, 1, n) {
			if (i == one)
				ans[i] = 1;
			else
				ans[i] = ask(1, one, i, n - 1);
		}
		
		cout << "! ";
		rep(i, 1, n)
			cout << ans[i] << " ";
		cout << endl;
	}
}