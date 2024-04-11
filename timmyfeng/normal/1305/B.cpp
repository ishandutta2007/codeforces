#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<int> rem;
	int j = (int)s.size() - 1;
	for (int i = 0; i < j; ++i) {
		if (s[i] == ')') continue;
		while (i < j && s[j] == '(') {
			--j;
		}
		if (j <= i) break;
		rem.push_back(i + 1);
		rem.push_back(j + 1);
		--j;
	}
	if (rem.empty()) {
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n';
		cout << rem.size() << '\n';
		sort(rem.begin(), rem.end());
		for (auto i : rem) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}