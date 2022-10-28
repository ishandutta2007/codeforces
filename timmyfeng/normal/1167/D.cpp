#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int bal = 0;
	for (auto i : s) {
		if (i == '(') {
			++bal;
			cout << bal % 2;
		} else {
			cout << bal % 2;
			--bal;
		}
	}
	cout << '\n';
}