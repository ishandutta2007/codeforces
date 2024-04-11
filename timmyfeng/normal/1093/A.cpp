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
		int lo = 0, hi = 0, cnt = 0;
		while (n < lo || n > hi) {
			++cnt;
			lo += 2;
			hi += 7;
		}
		cout << cnt << '\n';
	}
}