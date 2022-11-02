#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int cntL = 'z' - 'a' + 1;
		vector<int> cnt(cntL);
		for (char &c: s) ++cnt[c - 'a'];
		string res;
		for (char c = 'a'; c <= 'z'; c++) {
			if (cnt[c - 'a'] == 2) res += c;
		}
		for (char c = 'a'; c <= 'z'; c++) {
			if (cnt[c - 'a'] == 2) res += c;
		}
		for (char c = 'a'; c <= 'z'; c++) {
			if (cnt[c - 'a'] == 1) res += c;
		}
		cout << res << "\n";
	}
	return 0;
}