#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;

	int aa = a, bb = b;
	for (int i = 0, j = 0; i < n; i = j) {
		if (s[i] == '*') {
			++j;
			continue;
		}
		while (s[j] == '.') {
			++j;
		}
		int len = j - i;
		if (a > b) {
			a -= (len + 1) / 2;
			b -= len / 2;
		} else {
			b -= (len + 1) / 2;
			a -= len / 2;
		}
	}

	a = max(a, 0);
	b = max(b, 0);
	cout << aa - a + bb - b << '\n';
}