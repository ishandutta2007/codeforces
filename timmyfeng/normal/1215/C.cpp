#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> v1, v2;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a' && t[i] == 'b') {
			v1.push_back(i);
		} else if (s[i] == 'b' && t[i] == 'a') {
			v2.push_back(i);
		}
	}
	if (v1.size() % 2 != v2.size() % 2) {
		cout << -1 << '\n';
	} else {
		cout << v1.size() / 2 + v2.size() / 2 + (v1.size() % 2 ? 2 : 0) << '\n';
		auto prt = [](vector<int>& i) {
			for (int j = 0; j + 1 < i.size(); j += 2) {
				cout << i[j] + 1 << ' ' << i[j + 1] + 1 << '\n';
			}
		};
		prt(v1);
		prt(v2);
		if (v1.size() % 2) { 
			cout << v1.back() + 1 << ' ' << v1.back() + 1 << '\n';
			cout << v1.back() + 1 << ' ' << v2.back() + 1 << '\n';
		}
	}
}