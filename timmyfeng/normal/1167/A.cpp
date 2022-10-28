#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int i = find(s.begin(), s.end(), '8') - s.begin();
		cout << (n - i >= 11 ? "YES" : "NO") << '\n';
	}
}