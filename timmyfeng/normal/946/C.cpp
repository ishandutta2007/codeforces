#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	char cur = 'a';
	for (auto& i : s) {
		if (i <= cur && cur <= 'z') {
			i = cur++;
		}
	}

	if (cur > 'z') {
		cout << s << '\n';
	} else {
		cout << -1 << '\n';
	}
}