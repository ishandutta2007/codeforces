#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	
	for (int i = 0; i < n; ++i) {
		vector<int> freq(26);
		int mx = 0;
		for (int j = 1; i + j - 1 < n; ++j) {
			++freq[s[i + j - 1] - 'a'];
			mx = max(mx, freq[s[i + j - 1] - 'a']);
			if (mx <= j / 2) {
				cout << "YES" << '\n';
				cout << s.substr(i, j) << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';
}