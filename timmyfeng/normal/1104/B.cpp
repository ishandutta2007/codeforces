#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int cnt = 0;
	string stk;
	for (auto i : s) {
		if (stk.empty() || i != stk.back()) {
			stk.push_back(i);
		} else {
			stk.pop_back();
			++cnt;
		}
	}

	cout << (cnt % 2 ? "Yes" : "No") << "\n";
}