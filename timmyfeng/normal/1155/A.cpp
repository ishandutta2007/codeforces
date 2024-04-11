#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 1; i < n; ++i) {
		if (s[i] < s[i - 1]) {
			cout << "YES" << '\n';
			cout << i << ' ' << i + 1 << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}