#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int m = (n - 11) / 2;

	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '8') {
			pos.push_back(i);
		}
	}
	
	cout << ((int)pos.size() <= m || pos[m] > m * 2 ? "NO" : "YES") << '\n';
}