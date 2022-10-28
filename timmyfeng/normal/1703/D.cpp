#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
		int n; cin >> n;

		vector<string> strs(n);
		set<string> strs_set;
		for (auto &i : strs) {
			cin >> i;
			strs_set.insert(i);
		}

		for (auto i : strs) {
			bool exists = false;
			for (int l = 1; l < (int) i.size(); ++l) {
				exists |= strs_set.count(i.substr(0, l)) && strs_set.count(i.substr(l));
			}
			cout << exists;
		}
		cout << "\n";
    }
}