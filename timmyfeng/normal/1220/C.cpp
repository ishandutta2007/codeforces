#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	char mn = 'z';
	for (auto i : s) {
		if (mn < i) {
			cout << "Ann\n";
		} else {
			cout << "Mike\n";
			mn = i;
		}
	}
}