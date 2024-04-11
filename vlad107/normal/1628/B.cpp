#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		unordered_set<string> was_full;
		unordered_set<string> was_pref;
		bool found1 = false, found2 = false;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (found1 || found2) continue;
			if (s.size() == 1) {
				found1 = true;
			}
			
			was_full.insert(s);
			if (s.size() == 3) was_pref.insert(s.substr(0, 2));

			reverse(s.begin(), s.end());
			if ((was_full.count(s) != 0) || (was_pref.count(s) != 0)) {
				found2 = true;
			}
			if ((s.size() == 3) && (was_full.count(s.substr(0, 2)) != 0)) {
				found2 = true;
			}
		}
		if (found1 || found2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}