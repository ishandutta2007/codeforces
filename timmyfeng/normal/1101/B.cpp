#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	int i = find(s.begin(), s.end(), '[') - s.begin();
	int j = n - 1;
	while (j >= 0 && s[j] != ']') {
		--j;
	}
	if (i == n || j == -1 || i >= j) {
		cout << -1 << '\n';
		return 0;
	}
	i = find(s.begin() + i, s.end(), ':') - s.begin();
	while (j >= 0 && s[j] != ':') {
		--j;
	}
	if (i == n || j == -1 || i >= j) {
		cout << -1 << '\n';
		return 0;
	}
	cout << 4 + count(s.begin() + i + 1, s.begin() + j, '|') << '\n';
}